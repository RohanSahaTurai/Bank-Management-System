#include "Log.h"

/*******************************************************************************
 * Author: Rohan
 * This function gets the current system date and time
 * inputs:
 * - none
 * outputs:
 * - time
*******************************************************************************/

datetime_t get_time(void)
{
    /* bash command to get system time and store in 'time' file */
    system("date '+%d/%m/%Y %H:%M:%S' > time");

    FILE* fp;
    fp=fopen("time", "r");

    datetime_t time;

    fscanf(fp,"%d/%d/%d %d:%d:%d", &time.day, &time.month, &time.year,
                                   &time.hour, &time.minute, &time.seconds);

    fclose(fp);

    /* remove the 'time' file */
    system("rm time");

    return time;
}

/*******************************************************************************
 * Author: Rohan
 * This function appends one transaction record in the TrasactionLog file
 * inputs:
 * - const log_t log (log information to be saved)
 * outputs:
 * - none
*******************************************************************************/
void save_log(const log_t log)
{
    system("gzip -d " TRANS_LOG);

    FILE* fp;
    fp = fopen(TRANS_LOG, "a");

    fprintf(fp, "%d-%d-%-d %d-%d-%d %s %s %f\n",
            log.time.day, log.time.month, log.time.year,
            log.time.hour, log.time.minute, log.time.seconds,
            log.username, log.description, log.amount);

    fclose(fp);

    system("gzip " TRANS_LOG);
}

/*******************************************************************************
 * Author: Rohan
 * This function encrypts all the log information
 * inputs:
 * - log_t log (log to be encrypted)
 * outputs:
 * - log (encrypted log)
*******************************************************************************/

log_t encrypt_log(log_t log)
{
    /* encrypt the information */
    log.time.day^=XORkey;
    log.time.month^=XORkey;
    log.time.year^=XORkey;
    log.time.hour^=XORkey;
    log.time.minute^=XORkey;
    log.time.year^=XORkey;

    strcpy(log.username, XOR(log.username, XORkey));
    strcpy(log.description, XOR(log.description, XORkey));

    /* XOR encrypt amount which is a floating number */
    int temp_amount;
    temp_amount = (int)(log.amount*1000);

    log.amount=(float) (temp_amount ^ XORkey);

    return log;
}
/*******************************************************************************
 * Author: Rohan
 * This function decrypts all the log information
 * inputs:
 * - log_t log (log to be decrypted)
 * outputs:
 * - log (decrypted log)
*******************************************************************************/
log_t decrypt_log (log_t log)
{
    /* decrypt the information */
    log.time.day^=XORkey;
    log.time.month^=XORkey;
    log.time.year^=XORkey;
    log.time.hour^=XORkey;
    log.time.minute^=XORkey;
    log.time.year^=XORkey;

    strcpy(log.username, XOR(log.username, XORkey));
    strcpy(log.description, XOR(log.description, XORkey));


    /* decrypt amount which is a floating number */
    int temp_amount;
    temp_amount=((int)log.amount) ^ XORkey;
    log.amount=(float)temp_amount / 1000;

    return log;
}
/*******************************************************************************
 * Author: Rohan
 * This function prints the log information and the headings
 * inputs:
 * - log_t log (log info to be printed)
 * - int print_headings (flag to decide if headings need to be printed)
 * outputs:
 * - none
*******************************************************************************/
void print_log (log_t log, int print_headings)
{
    if (print_headings==TRUE)
    {
        printf("\nDATE      \tTIME    \tUSER      \tDescription\t\tAmount\n"
               "---------------------------------------------------------"
               "--------------------------------\n");
    }

    printf( "%02d/%02d/%04d\t%02d:%02d:%02d\t%-10s\t%-20s\t$%0.2f\n",
            log.time.day, log.time.month, log.time.year,
            log.time.hour, log.time.minute, log.time.seconds,
            log.username, log.description, log.amount);
}

/*******************************************************************************
 * Author: Rohan
 * This function gets the log info from the external functions and saves the
 * encrypted log info.
 * - const char* username (username of who is making the transaction)
 * - const char* description (what type of transaction is made)
 * - const float amount (amount of money transacted)
 * outputs:
 * - none
*******************************************************************************/
void add_log
(const char* username, const char* description, const float amount)
{
    datetime_t current_time=get_time();

    log_t log;

    log.time = current_time;
    strcpy(log.username, username);
    strcpy(log.description, description);
    log.amount=amount;

    /* save the encrypted log in the file */
    save_log(encrypt_log(log));
}

/*******************************************************************************
 * Author: Rohan
 * This function prints the log information of the username requested
 * inputs:
 * - char* username (the username whose log is to be printed)
 * outputs:
 * - none
*******************************************************************************/
void view_log_username (char* search_username)
{
    system("gzip -d " TRANS_LOG);

    system("clear");

    FILE* fp;

    fp=fopen(TRANS_LOG, "r");

    log_t log;

    /* if file is not found, then no transaction had been made */
    if(fp!=NULL)
    {
        char current_username[MAX_USERNAME_LEN+1];

        int log_found = FALSE;

        int print_headings = TRUE;

        while(fgetc(fp)!=EOF)
        {
          fseek(fp, -1, SEEK_CUR);

          fscanf(fp, "%d-%d-%d %d-%d-%d %s %s %f\n",
                     &log.time.day, &log.time.month, &log.time.year,
                     &log.time.hour, &log.time.minute, &log.time.seconds,
                     log.username, log.description, &log.amount);


          strcpy(current_username, log.username);

         /* searches the log info of the username requested */
          if(strcmp(search_username, XOR(current_username, XORkey))==0)
          {
              print_log(decrypt_log(log), print_headings);

              /* Don't print headings after first transaction printed */
              print_headings = FALSE;

              log_found = TRUE; /* set flag true if log is found */
          }

        }

        fclose(fp);

        system("gzip " TRANS_LOG);

        if(log_found==FALSE)
            printf("No Transaction Found!\n");

        else
        {
            printf("\nPress Enter to continue . . . ");
            while(getchar()!='\n');
            system("clear");
        }

    }

    else
        printf("No Transaction Found!\n");
}
/*******************************************************************************
 * Author: Rohan
 * This function prints all the log information stored
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void view_all_logs (void)
{
    system("gzip -d " TRANS_LOG);

    system("clear");

    FILE* fp;

    fp=fopen(TRANS_LOG, "r");

    log_t log;

    /* if file is not found, then no transaction had been made */
    if(fp!=NULL)
    {
        int print_headings = TRUE;

        while(fgetc(fp)!=EOF)
        {
          fseek(fp, -1, SEEK_CUR);

          fscanf(fp, "%d-%d-%d %d-%d-%d %s %s %f\n",
                     &log.time.day, &log.time.month, &log.time.year,
                     &log.time.hour, &log.time.minute, &log.time.seconds,
                     log.username, log.description, &log.amount);

          print_log(decrypt_log(log), print_headings);

          /* Don't print headings after first transaction printed */
          print_headings=FALSE;

        }

        fclose(fp);

        system("gzip " TRANS_LOG);

        printf("\nPress Enter to continuee . . . ");
        while(getchar()!='\n');
        system("clear");
    }

    else
     printf("No Transaction Found!\n");
}
