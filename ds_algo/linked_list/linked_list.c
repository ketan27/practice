#include "linked_list.h"

/* OPEN ISSUES
 * 1- Do the insertion at human like position. For e.g. inserting at 2nd should mean literally 
 * second. 1->3->4 should become 1->2->3->4
 *
 * 2- Elaborate debug message to include variable length args
 */

int SLL_SIZE = 0;

sll_node *create_sll_node(int data)
{
#ifdef DBG
    printf("%s called\n", __func__);
#endif

    sll_node *new_node = (sll_node *)malloc(sizeof(sll_node));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

int add_node_to_sll(int pos, sll_node **head, int data)
{
    int ret = SUCCESS;

#ifdef DBG
    printf("%s called\n", __func__);
#endif

    sll_node *node = create_sll_node(data);

    if (!node) {
        printf("Failed to allocate memory!\n");
        ret = ERROR;
        goto end;
    }

    if (*head == NULL) {
        *head = node;
        goto end;
    }

    // we should stop one hop before to insert at human friendly position.
    if (pos)
        --pos;

    if (pos == 0) {
        // insertion at the beginning.
        node->next = *head;
        *head = node;
    } else {

        // hop to correct node to insert it.
        sll_node *tmp = *head;
        while (pos && tmp->next) {
            tmp = tmp->next;
            pos--;
#ifdef DBG
            printf("Done for position %d\n", pos);
#endif
        }

        if (pos) {
            // we still have some hops left as per user's input
            printf("Entered position is larger than or equal to the current size of linked list,"
                   " instead inserting at the end\n");
        }

        node->next = tmp->next;
        tmp->next = node;
        tmp = node;
    }

end:
#ifdef DBG
    printf("Node with value %d added successfully\n", node->data);
#endif
    SLL_SIZE++;
    return ret;
}

int traverse_sll(sll_node *head)
{
    ENTER_MSG;

    sll_node *tmp = head;

    while(tmp) {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");

    return SUCCESS;
}

int delete_node_from_sll(int pos, sll_node **head)
{
    ENTER_MSG;

    int ret = ERROR;

    if (*head == NULL) {
        ret = SUCCESS;
        printf("Linked list empty, exiting without deleting\n");
        return ret;
    }

    sll_node *tmp = *head;
    if (pos) {
        // to stop at one hop before the node to be deleted
        pos--;
    }

    if (pos == 0) {
        *head = (*head)->next;
        free(tmp);
    } else {
        /* in human terminology, position starts from 1 while 'while' loop thinks from 0, to adjust 
         * that pos should not be less than 1.
         */
        while ((pos > 1) && tmp->next) {
            pos--;
            tmp = tmp->next;
        }

        if (pos > 1) {
            printf("You entered position which is greated than the size of linked list, not deleting\n");
            return ret;
        }

        sll_node *node_to_be_deleted = tmp->next;
        tmp->next = node_to_be_deleted->next;
        free(node_to_be_deleted);
    }

    ret = SUCCESS;
    printf("Deleted...\n");
    return ret;
}

/***************************** DOUBLY LINKED LIST ********************************/

dll_node* create_dll_node(int data)
{
    ENTER_MSG;

    dll_node *new_node = (dll_node*)malloc(sizeof(dll_node));

    if (new_node) {
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        printf("Failed to allocate memory\n");
    }

    return new_node;
}

int add_node_to_dll(int pos, dll_node **head, int data)
{
    ENTER_MSG;

    dll_node *node = create_dll_node(data);

    if (!*head) {
        *head = node;

        if (pos) {
            printf("No element existed, adding in the head instead of %d pos\n", pos);
        }

        return SUCCESS;
    }



}




