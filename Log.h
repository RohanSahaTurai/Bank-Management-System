#ifndef LOG_H
#define LOG_H

#include <stdio.h>  /*printf, fprintf, fscanf */
#include <stdlib.h> /* system() */
#include <string.h> /* strcpy, strcmp */

/*******************************************************************************
* Preprocessing Directives
*******************************************************************************/

#include "Encrypt.h"

#define TRANS_LOG "TransactionLog"
#define MAX_DESCRIPTION_LEN 20
#define MAX_USERNAME_LEN 10
#define XORkey '@'

#define TRUE 1
#define FALSE 0

/*******************************************************************************
* Custom Defined Structures
*******************************************************************************/
struct date_time
{
    int day;
    int month;
    int year;

    int hour;
    int minute;
    int seconds;
};
typedef struct date_time datetime_t;

struct log
{
    datetime_t time;
    char username[MAX_USERNAME_LEN+1];
    char description[MAX_DESCRIPTION_LEN+1];
    float amount;
};
typedef struct log log_t;

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
datetime_t get_time(void);
void save_log(const log_t log);
log_t encrypt_log(log_t log);
log_t decrypt_log(log_t log);
void print_log(log_t log, int print_headings);
void add_log(const char* username, const char* description, const float amount);
void view_log_username(char* search_username);
void view_all_logs(void);

#endif


