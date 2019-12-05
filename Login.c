#include "Login.h"

#define MAX_USERNAME 10
#define MAX_PASSWORD 10
#define DATABASE "user.txt"
/*colours*/
#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"
#define RESET    "\x1B[0m"

#define ADMIN_PASSWORD "password"


/*******************************************************************************
 * Author: Matthew, Sophie
 * This function searches checks for admin login, otherwise finds and logs in
 * the user.
 * inputs:
 * - head of the user list.
 * outputs:
 * - null if admin, otherwise a pointer to the user.
*******************************************************************************/
node_t* login(node_t* head)
{
    char username[MAX_USERNAME];
    node_t* node = NULL;

    system("clear");

    printf("\n\t\t\t Welcome to Bank\n\n");

    #ifdef DEBUG
        printf("admin login username is 'admin'.\n\n");
    #endif

    while(node == NULL)
    {
        printf("\t Username:");
        scanf("%s", username);

        if (strcmp(username, "admin") == 0)
        {
           /*return when its admin*/
            return NULL;
        }
        else
        {
            node = find_node(head, username);
            if(node == NULL)
            {
                printf(RED "\n\t This Username Does Not Exist.\n\n" RESET);
            }
            else
            {
                /*return when is user*/
                return(node);
            }
        }
    }
    return 0;
}

/*******************************************************************************
 * Author: Matthew
 * This function searches checks for admin login, otherwise finds and logs in
 * the user.
 * inputs:
 * - head of the user list.
 * outputs:
 * - null if admin, otherwise a pointer to the user.
*******************************************************************************/
int user_password(const node_t* node)
{
    char pass[MAX_PASSWORD];
    int exit = 1;
    /*printf("%s\n", saved_password );*/

    while(exit <= 3)
    {
        printf("\t Password:");
        system("stty -echo"); /* Turns off character display */
        scanf("%s",pass);
        system("stty echo"); /* Turn echoing of characters back on */

        /*User password compare*/
        if(strcmp(node->user.login.password, pass) != 0)
        {
            printf(RED "\n\n\t *Wrong Password*\n\n" RESET);
            printf("\t Attempt %d\n",exit+1);
            exit++;
        }
        else
        {
            system("clear");
            printf("\n\n\t Welcome to your Account, %s %s \n\n",
                    node->user.first_name, node->user.last_name);
            return 1; /*return 1 when user signed in*/
        }
    }

    printf(RED "\n\n\t Sorry you are locked out.\n\n" RESET);
    system("clear");
    return 0;
}

/*******************************************************************************
 * Author: Matthew
 * This function requests the password for the admin account and
 * the user.
 * inputs:
 * - head of the user list.
 * outputs:
 * - null if admin, otherwise a pointer to the user.
*******************************************************************************/
int admin_password()
{
     #ifdef DEBUG
        printf("\nadmin password is 'password'.\n\n");
     #endif

    char pass[MAX_PASSWORD];
    int exit = 1;

    while (exit < 6)
    {
        printf("\t Password:");
        /* Turns off character display */
        system("stty -echo");
        scanf("%s",pass);
        /* Turn echoing of characters back on */
        system("stty echo");

        /*Admin password compear*/
        if(strcmp(ADMIN_PASSWORD, pass) != 0)
        {
            exit++;
            printf(RED "\n\n\t *Wrong Password*\n\n"RESET);
            printf("\t Attempt %d\n", exit);
        }
        else
            /* return 1 when admin signed in */
            return 1;
    }
    printf(RED "\n\t Sorry you are locked out.\n" RESET);
    system("clear");
    return 0;
}
