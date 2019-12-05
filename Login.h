#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"

node_t* login(node_t* head);
int user_password(const node_t* node);
int admin_password();

#endif
