#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Validate.h"
#include "Log.h"

void delete_user(node_t* head);
void edit_user(char * property, char* property_name);
void change_password(node_t* head, node_t* node);
void edit_info_menu(node_t* head);
void view_user_info(node_t* head);
void view_transaction_logs();


#endif
