/*
 * This file contains solutions to Kanumanchi Single Linked List problems.
 * Idea is to keep adding functions pertaining to specific problems and then call them directly via 
 * main(). So time would be saved in building up the driver for linked list.
 */

#include "linked_list.h"

sll_node *reverse_linked_list_in_pair_recursively(sll_node *head)
{
    sll_node *next = NULL;

    if (!head || !(head->next)) {
        // for a 0 or 1 node list, return that itself
        return head;
    } else {
        next = head->next;
        head->next = next->next;
        next->next = head;
        head = next;
        head->next->next = reverse_linked_list_in_pair_recursively(head->next->next);
        return head;
    }
}

/**
 * Reverse linked list in pairs iteratively
 */
sll_node *reverse_linked_list_in_pair_iteratively(sll_node *head)
{
    sll_node *cur = head, *prev = NULL, *next = NULL;
    sll_node *new_head = NULL;

    while (cur && cur->next) {
        next = cur->next;
        cur->next = next->next;
        next->next = cur;
        if (prev) {
            prev->next = next;
        }
        prev = cur;
        cur = cur->next;

        if (!new_head)
            new_head = next;
    }

    return new_head;
}

/**
 * Program to merge 2 sorted linked list
 */
sll_node *mergeList(sll_node *a, sll_node *b)
{
    sll_node *res = NULL, *tmp = NULL;

    while (a && b) {
        if (a->data < b->data) {
            tmp = a;
            a = a->next;
        } else {
            tmp = b;
            b = b->next;
        }

        add_node_to_sll(0, &res, tmp->data); 
    }
    return res;
}

/**
 * Program to display reverse of linked list from the end without actually destroying the order of
 * its nodes. And also without any other struct to cache values like array or Stack.
 */
void print_reverse(sll_node *head)
{
    if (head == NULL) {
        // we are at the end of the list here.
        return;
    }
    print_reverse(head->next);
    printf("%d->", head->data);
}

/**
 * This is the most efficient approach, other usual ones would need either O(n2) or O(n)
 * but this takes O(n/2)
 * TODO - Fix the segmentation fault in case of even nodes
 */
void find_middle_of_linked_list(sll_node *head)
{
    sll_node *ptr1, *ptr2;
    ptr1 = ptr2 = head;

    while(ptr2 && ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }

    printf("Middle node is %d\n", ptr1->data);
}

/*
 * Two linked list merge at what node? Something like this -
 * 1 -> 2 -> 3 ->
 *                > 4 -> 5 -> 6 -> 7
 *           3 ->
 * Merge point is 4.
 */
void find_merge_point(sll_node *list1, sll_node *list2)
{
    int len1 = 0, len2 = 0, diff = 0;
    sll_node *head1, *head2;

    head1 = list1;
    head2 = list2;

    while (head1) {
        len1++;
        head1 = head1->next;
    }

    while (head2) {
        len2++;
        head2 = head2->next;
    }

    // Both heads would be NULL by now
    // head1 is always meant to store head of bigger list.
    if (len2 > len1) {
        diff = len2 - len1;
        head1 = list2;
        head2 = list1;
    } else {
        diff = len1 - len2;
        head1 = list1;
        head2 = list2;
    }

    while (diff--) {
        head1 = head1->next;
    }

    while (head1 && head2) {
        if (head1 == head2) {
            printf("Merge node is %d\n", head1->data);
            return;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // would reach here only if merge is not found, else while loop's return would have happened.
    printf("Lists are not merged\n");
}

void reverse_list_iterative(sll_node **head)
{
    sll_node *prev = NULL, *next = NULL;

    do {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;

        if (next)
            *head = next;
    } while(next);
}

void reverse_list_recursive(sll_node **head)
{
    sll_node *first = NULL;
    sll_node *rest = NULL;

    if (*head == NULL) {
        // List is empty, return.
        return;
    }

    first = *head;
    rest = first->next;

    if (rest == NULL) {
        // List has only one node.
        return;
    }

    reverse_list_recursive(&rest);

    // Connect first to the rest list since it should have got reversed by now.
    first->next->next = first;
    first->next = NULL;
    *head = rest;
}

void find_n_node(sll_node *head, int n)
{
    int pos = n;
    sll_node *pt1 = NULL;
    sll_node *pt2 = head;

    while(n-- > 1) {
        if (pt2)
            pt2 = pt2->next;
    }

    while (pt2) {
        if (pt1 == NULL)
            pt1 = head;
        else
            pt1 = pt1->next;

        pt2 = pt2->next;
    }

    if (pt1)
        printf("Value of %d node is %d\n", pos, pt1->data);
    else
        printf("Entered position (%d) is far greated than the size of linked list\n", pos);

}

int main()
{
    sll_node *list1 = NULL;

    int i;

    for (i = 9; i >= 0; --i) {
        add_node_to_sll(0, &list1, i);
    }

    traverse_sll(list1);

    //find_n_node(head, 100);

    //reverse_list_iterative(&head);
    //reverse_list_recursive(&head);

    //list1->next->next->next->next = list2->next->next->next->next->next;
    //find_merge_point(list1, list2);

    //find_middle_of_linked_list(list1);

    //print_reverse(list1);

    //sll_node *list3 = mergeList(list1, list2);

    sll_node *list3 = reverse_linked_list_in_pair_iteratively(list1);
    traverse_sll(list3);

    return 0;
}

