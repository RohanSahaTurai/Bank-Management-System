#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FIRSTNAME_LEN 256
#define MAX_LASTNAME_LEN 256
#define MAX_EMAIL_LEN 256
#define MAX_ADDRESS_LEN 256
#define MAX_USERNAME_LEN 10
#define MAX_PHONE_LEN 10
#define MAX_PASSWORD_LEN 10

typedef struct DOB
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
} DOB_t;

typedef struct login
{
    char username [MAX_USERNAME_LEN+1];
    char password [MAX_PASSWORD_LEN+1];
} login_t;

typedef struct user
{
    login_t login;
    char first_name[MAX_FIRSTNAME_LEN+1];
    char last_name[MAX_LASTNAME_LEN+1];
    DOB_t DOB;
    char phone[MAX_PHONE_LEN+1];
    char email[MAX_EMAIL_LEN+1];
    char address[MAX_ADDRESS_LEN+1];
    float balance;
} user_t;

typedef struct node
{
    user_t user;
    struct node* next;
    struct node* previous;
} node_t;

node_t* create_head(const user_t new_user);
node_t* insert_node (node_t* head, user_t new_user);
node_t* remove_head (node_t* current_head);
void remove_tail (node_t* current_tail);
node_t* remove_node (node_t* current_head, node_t* to_be_deleted);
node_t* find_node (node_t* head, char* search_username);
void print_user (const user_t user);
void print_all_users (node_t* head);

#endif
