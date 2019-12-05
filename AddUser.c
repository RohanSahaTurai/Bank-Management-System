#include "AddUser.h"

#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"
#define RESET    "\x1B[0m"

#define TRUE 1
#define FALSE 0

/*******************************************************************************
 * Author: Rohan
 * This function adds a user in RAM with all instructions on how to use
 * this program.
 * inputs:
 * - users_t* temp_user ; points to the elements of users array
 * - int total_users; stores the number of flights currently stored in
 *   users array
 * outputs:
 * - none
*******************************************************************************/
node_t* add_user(node_t* head, int* total_users)
{
    system("clear");

    printf(CYAN"Please provide the following personal information\n\n"
           "----------------------------------------------------\n"RESET);

    user_t temp_user;

    /* Get First Name */
    while (1)
    {
        printf(GREEN"\nFirst Name>\n"RESET);

        scanf("%[^\n]", temp_user.first_name);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate first name */
        if (is_valid_name(temp_user.first_name) == TRUE)
        {
            break;
        }

        printf(RED"Invalid input.\n"RESET);
    }

    /* Get Last Name */
    while(1)
    {
        printf(GREEN"\nLast Name>\n"RESET);

        scanf("%[^\n]", temp_user.last_name);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate last name */
        if (is_valid_name(temp_user.last_name) == TRUE)
        {
            break;
        }

        printf(RED"Invalid input.\n"RESET);
    }

    /* Get DOB */
    while (1)
    {
        printf(GREEN"\nDOB (dd/mm/yyyy)>\n"RESET);

        scanf("%d/%d/%d", &temp_user.DOB.day,
                          &temp_user.DOB.month,
                          &temp_user.DOB.year);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate DOB */
        if(is_valid_DOB( temp_user.DOB.day,
                         temp_user.DOB.month,
                         temp_user.DOB.year)==TRUE)
        {
            break;
        }

        printf(RED"Invalid input.\n"RESET);
    }


    /* Get Phone Number */
    while(1)
    {
        printf(GREEN"\nPhone>\n"RESET);

        scanf("%[^\n]", temp_user.phone);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate phone */
        if(is_valid_phone(temp_user.phone)==TRUE)
        {
            break;
        }

        printf(RED"Invalid input.\n"RESET);
    }

    /* Get Email */
    while(1)
    {
        printf(GREEN"\nEmail>\n"RESET);

        scanf("%[^\n]", temp_user.email);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate email */
        if(is_valid_email(temp_user.email)==TRUE)
        {
            break;
        }

        printf(RED"Invalid input.\n"RESET);
    }

    /* Get Address */
    while(1)
    {
        printf(GREEN"\nAddress>\n"RESET);

        temp_user.address[0]='\0';

        scanf("%[^\n]", temp_user.address);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* Checks Address if field is empty */
        if(temp_user.address[0]!='\0' || temp_user.address[0]!=' ')
            break;

        printf(RED"Invalid input.\n"RESET);
    }

    system("clear");

    printf(CYAN"Please select a Username and Password\n\n"
           "-----------------------------------------------------\n"RESET);

    printf(YELLOW"\nUsername must have\n"
           "  1) at most 10 characters\n"
           "  2) no spaces in between\n"RESET);

    printf(YELLOW"\nPassword must have\n"
           "  1) at least 8 characters\n"
           "  2) combination of uppercase and lowercase letters\n"
           "  3) at least one digit\n"RESET);


    /* Get Username */
    while(1)
    {
        printf(GREEN"\n\tUsername: "RESET);
        scanf("%[^\n]", temp_user.login.username);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* search for duplicates */
        if(is_valid_username(temp_user.login.username)==TRUE)
        {
            if(find_node(head, temp_user.login.username)==NULL)
            {
                break;
            }

            printf(RED"\tThis username is already in use.\n"RESET);
        }

        printf(RED"\tInvalid username\n"RESET);
    }


    /* Get Password */
    while(1)
    {
        printf(GREEN"\n\tPassword: "RESET);
        scanf("%[^\n]", temp_user.login.password);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* check for password validity */
        if(is_valid_password(temp_user.login.password) == TRUE)
        {
            break;
        }

        printf(RED"\tPassword is too weak.\n"RESET);
    }

    /* creates a new balance account with initial balance $0.00 */

    system("clear");

    temp_user.balance=0.00;

    printf(YELLOW"User %s has been created successfully!\n", temp_user.first_name);
    printf("\nAccount Details:\n\n");
    printf("\tAccount Type: Balance\n\tNet Balance: $%.2f\n"RESET, temp_user.balance);
    printf(GREEN"\n\n\n\nPress Enter to continue..."RESET);
    while (getchar()!='\n'); /* waits for the user to press Enter to exit */
    system("clear");


    if(*(total_users) == 0)
        head=create_head(temp_user);

    else
        insert_node(head, temp_user);

    ++*(total_users);

    return head;
}
