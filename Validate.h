#ifndef VALIDATE_H
#define VALIDATE_H

#include <stdio.h>
#include <string.h>

#include "LinkedList.h"

#define TRUE 1
#define FALSE 0

int is_valid_DOB(const int day, const int month, const int year);
int is_valid_name(const char* name_p);
int is_valid_phone(const char* phone_p);
int is_valid_password(const char* password_p);
int is_valid_username(const char* username);
int is_valid_email(const char* email);

#endif
