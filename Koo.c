#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_list
{
    int val;
    struct linked_list* next;
} list;

list* new_node(int val)
{
    list* ptr = (list*) malloc (sizeof(list));
    if (ptr == NULL)
    {
        perror("node create failure");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;
    return ptr;
}

void print(list** head)
{
    list* ptr = *head;
    if (!ptr)
        printf("blank list\n");
    else
    {
        printf("HEAD ");
        while (ptr)
        {
            printf(" --> %d", ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void add(list** head, int val)
{
    list* ptr = *head;
    if (!ptr)
        *head = new_node(val);
    else
    {
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new_node(val);
    }
}

void del(list** head, int val)
{
    list* ptr = *head, *tmp;
    if (ptr == NULL)
        printf("blank list\n");
    else if (ptr->val == val)
    {
        *head = ptr->next;
        free(ptr);
    }
    else
    {
        bool flag = false;
        while (ptr && ptr->next)
        {
            if (ptr->next->val == val)
            {
                tmp = ptr->next;
                ptr->next = ptr->next->next;
                free(tmp);
                flag = true;
            }
            ptr = ptr->next;
        }
        if (!flag)
            printf("item not found\n");
    }
}

void clear(list** head)
{
    list* ptr = *head, *tmp;
    while (ptr)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    *head = NULL;
    printf("list cleared\n");
}

int main()
{
    list** HEAD;

    // Initialize HEAD of the linked list
    HEAD = (list**) malloc(sizeof(list*));
    *HEAD = NULL; // Set the head to NULL indicating an empty list

    int ch, val;
    while (1)
    {
        printf("Enter your choice\n\t1: Display list\n\t2: Add an element\n\t3: Remove an element\n\t4: Clear list\n\t5: Exit\n\nchoice:: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                // Display
                print(HEAD);
                break;
            case 2:
                // Add
                printf("Enter value to insert:: ");
                scanf("%d", &val);
                add(HEAD, val);
                break;
            case 3:
                // Delete
                printf("Enter value to be deleted:: ");
                scanf("%d", &val);
                del(HEAD, val);
                break;
            case 4:
                // Clear List
                clear(HEAD);
                break;
            default:
                clear(HEAD);
                // Free the head
                free(HEAD);
                printf("Bye Bye!\n");
                exit(0);
        }
    }
}

