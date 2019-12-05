#include "Validate.h"


/*******************************************************************************
 * Author: Rohan
 * This function checks if the DOB is a valid entry
 * inputs:
 * - integer date including day, month and year
 * outputs:
 * - 1 if valid, 0 if invalid
*******************************************************************************/
int is_valid_DOB(const int day, const int month, const int year)
{
    /* 'is_valid' is used as flag to check error */
    int is_valid=FALSE;

    if(month>=1 && month<=12 &&
       day>=1 && day<=31 &&
       year>=1900 && year<=2090)
    {
        is_valid = TRUE;
    }

    return is_valid;
}

/*******************************************************************************
 * Author: Rohan
 * This function checks if the name is valid
 * inputs:
 * - name
 * outputs:
 * - 1 if valid, 0 if invalid
*******************************************************************************/
int is_valid_name(const char* name_p)
{
    int i; /* counter */

    int is_valid=FALSE; /* used as flag to check error */

    for(i=0; name_p[i]!='\0'; i++)
    {
        if(!((name_p[i]>='A' && name_p[i]<='Z') ||
             (name_p[i]>='a' && name_p[i]<='z') ||
              name_p[i]==' ' || name_p[i] == '-'))
        {
            is_valid=FALSE;
            break;
        }

        is_valid=TRUE;
    }

    return is_valid;
}

/*******************************************************************************
 * Author: Rohan
 * This function checks if the phone number is valid
 * inputs:
 * - phone number
 * outputs:
 * - 1 if valid, 0 if invalid
*******************************************************************************/
int is_valid_phone(const char* phone_p)
{
    int i; /* counter */

    int length;

    int is_valid=FALSE;

    for(length=0; phone_p[length]!='\0'; length++);

    if(length==10)
    {
        for(i=0; phone_p[i]!='\0'; i++)
        {
            if(!(phone_p[i]>='0' && phone_p[i]<='9'))
            {
                is_valid=FALSE;
                break;
            }

            is_valid=TRUE;
        }

    }

    return is_valid;
}

/*******************************************************************************
 * Author: Rohan
 * This function checks if the password meets the criteria
 * inputs:
 * - password
 * outputs:
 * - 1 if valid, 0 if invalid
*******************************************************************************/
int is_valid_password(const char* password_p)
{
    int i; /* counter */

    int length;

    int is_valid=FALSE;

    int numbers=FALSE;
    int uppercase=FALSE;
    int lowercase=FALSE;

    for(length=0; password_p[length]!='\0'; length++);

    if(length>=8)
    {
        for(i=0; password_p[i]!='\0'; i++)
        {
            if(password_p[i]>='A' && password_p[i]<='Z')
                uppercase=TRUE;

            else if(password_p[i]>='a' && password_p[i]<='z')
                lowercase=TRUE;

            else if(password_p[i]>='0' && password_p[i]<='9')
                numbers=TRUE;
        }
    }

    if(uppercase==TRUE && lowercase==TRUE && numbers==TRUE)
        is_valid=TRUE;

    return is_valid;
}

/*******************************************************************************
 * Author: Rohan
 * This function checks if the username meets teh criteria
 * inputs:
 * - username
 * outputs:
 * - 1 if valid, 0 if invalid
*******************************************************************************/
int is_valid_username(const char* username)
{
    int length;

    int is_valid = FALSE;

    for(length=0; length!='\0'; length++){}

        if(length<=10)
        {
            int i;

            for(i=0; username[i]!='\0'; i++)
            {

                if(username[i] == ' ')
                {
                    is_valid = FALSE;
                    break;
                }

                is_valid = TRUE;
            }
        }

    return is_valid;
}

/*******************************************************************************
 * Author: Rohan
 * This function checks if a email is valid
 * inputs:
 * - email address
 * outputs:
 * - 1 if valid, 0 if invalid
*******************************************************************************/
int is_valid_email(const char* email)
{
    int is_valid=FALSE;

    char* char_at=NULL;
    char* char_dot=NULL;
    char* char_space=NULL;

    char_at=strchr(email,'@'); /* checks if @ is present */
    char_space=strchr(email, ' '); /* checks if space is present */

    if(char_at!=NULL && char_space==NULL)
    {
        char_dot=strrchr(char_at+1, '.'); /* checks if . is present */

        /* checks for double occurrences of @ */
        char_at=strchr(char_at+1,'@');

        if(char_dot!=NULL && char_at==NULL && *(char_dot+1)!='\0')
        {
            is_valid=TRUE;
        }
    }

    return is_valid;
}
