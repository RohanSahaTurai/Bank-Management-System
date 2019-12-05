#include "LinkedList.h"

/*******************************************************************************
 * Author: Rohan
 * This function creates the head of the linked list.
 * inputs:
 * - number of users currently in system
 * outputs:
 * - ppinter to node
*******************************************************************************/
node_t* create_head(const user_t new_user)
{
    node_t* head = NULL;

    head = (node_t*) malloc(sizeof(node_t));

    if(head == NULL)
        return NULL;

    head->user = new_user;
    head->next = NULL;
    head->previous = NULL;

    return head;
}

/*******************************************************************************
 * Author: Rohan
 * This function inserts node at the end of linked list.
 * inputs:
 * - pointer to first node, newly created user
 * outputs:
 * - pointer to node
*******************************************************************************/
node_t* insert_node (node_t* head, user_t new_user)
{
    node_t* current = head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = (node_t*) malloc(sizeof(node_t));

    node_t* new_node = current->next;

    if(new_node == NULL)
    {
        return NULL;
    }

    new_node->user = new_user;
    new_node->next = NULL;
    new_node->previous = current;

    return new_node;
}

/*******************************************************************************
 * Author: Rohan
 * This function removes the first node in the linked list.
 * inputs:
 * - pointer to first node
 * outputs:
 * - pointer to head
*******************************************************************************/
node_t* remove_head (node_t* current_head)
{
    node_t* new_head = current_head->next;

    new_head->previous = NULL;

    free(current_head);

    current_head=NULL;

    return new_head;
}

/*******************************************************************************
 * Author: Rohan
 * This function removes the last node in the linked list.
 * inputs:
 * - pointer to last node
 * outputs:
 * - none
*******************************************************************************/
void remove_tail (node_t* current_tail)
{
    node_t* new_tail = current_tail->previous;

    new_tail->next = NULL;

    free(current_tail);
    current_tail = NULL;
}

/*******************************************************************************
 * Author: Rohan
 * This function removes nodes at a specified address.
 * inputs:
 * - pointer to first node, node to be deleted 
 * outputs:
 * - pointer to head
*******************************************************************************/
node_t* remove_node (node_t* current_head, node_t* to_be_deleted)
{
    node_t* new_head;

    if(to_be_deleted->previous==NULL)
    {
        new_head=remove_head(to_be_deleted);
        return new_head;
    }
    else if (to_be_deleted->next==NULL)
        remove_tail(to_be_deleted);
    else
    {
        node_t* before =  to_be_deleted->previous;
        node_t* after = to_be_deleted->next;

        before->next=after;
        after->previous=before;

        printf("middle\n");

        /* Free the deleted node */
        free(to_be_deleted);

        to_be_deleted=NULL;
    }

    return current_head;
}

/*******************************************************************************
 * Author: Rohan
 * This function returns the addres of a specific node.
 * inputs:
 * - pointer to head of the list.
 * - username of the node to find.
 * outputs:
 * - pointer to the found node, null if not found.
*******************************************************************************/
node_t* find_node (node_t* head, char* search_username)
{
    /* Iterate through linked list*/
    node_t* current;
    for (current = head; current != NULL; current = current->next) 
    {
        if(strcmp(current->user.login.username, search_username) == 0)
            return current;
    }
    return NULL;
}

/*******************************************************************************
 * Author: Rohan
 * This function prints the user struct.
 * inputs:
 * - user 
 * outputs:
 * - none
*******************************************************************************/
void print_user (const user_t user)
{
    printf("---------------------------------\n");
    printf("Username: %s\n", user.login.username); 
    printf("First name: %s\n", user.first_name);
    printf("Last name: %s\n", user.last_name);
    printf("DOB: %02d/%02d/%04d\n", user.DOB.day, user.DOB.month, user.DOB.year);
    printf("Phone: %s\n", user.phone);
    printf("Email: %s\n", user.email);
    printf("Address: %s\n", user.address);
    printf("---------------------------------\n");
}

/*******************************************************************************
 * Author: Rohan
 * This function prints all nodes in the linked list.
 * inputs:
 * - pointer to head of the list
 * outputs:
 * - none
*******************************************************************************/
void print_all_users (node_t* head)
{
    /* Iterate through linked list*/
    node_t* current;
    for (current = head; current != NULL; current = current->next) 
    {
        print_user(current->user);
    }
}
