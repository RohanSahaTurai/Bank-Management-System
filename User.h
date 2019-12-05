#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Encrypt.h"
#include "Log.h"

#define DATABASE "user.txt"
#define XOR_KEY '!'

void deposit(node_t* node);
void withdraw(node_t* node);
void transfer(node_t* head, node_t* node);
void save_user(FILE* fp, const user_t user);
void save_users(node_t* head);
node_t* load_users(int* total_users);

#endif
