#ifndef ADD_USER_H
#define ADD_USER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Validate.h"

#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"
#define RESET    "\x1B[0m"

node_t* add_user(node_t* head, int* total_users);
void user_set_lastname(user_t temp_user);
void user_set_DOB(user_t temp_user);
void user_set_phone(user_t temp_user);
void user_set_email(user_t temp_user);
void user_set_address(user_t temp_user);
void user_set_username(node_t* head, user_t temp_user);
void user_set_password(user_t temp_user);

#endif
