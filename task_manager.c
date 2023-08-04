#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Task{
    int taskId;
    char description[20];
    int priority;
    struct Task *next;
};
void displayTasks(struct Task *temp)
{
    while(temp!=NULL)
    {
        printf("\nThe task Id is %d",temp->taskId);
        printf("\nThe task description is %s",temp->description);
        printf("\nThe task priority is %d",temp->priority);
        printf("\n");
        temp=temp->next;
    }
}
void addTask(int t,char a[],int p,struct Task *temp)
{
    struct Task *new;
    new=malloc(sizeof(struct Task));
    new->taskId=t;
    strcpy(new->description,a);
    new->priority=p;
    new->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
}
void deleteTask(int t,struct Task *temp)
{
    if(temp==NULL)
    {
        printf("No tasks to delete");
        return; 
    }
    struct Task *prev=NULL;
    while(temp!=NULL)
    {
        if(temp->taskId==t)
        {
            if(prev==NULL)
            {
                temp=temp->next;
            }
            else
            {
                prev->next=temp->next;
            }
            free(temp);
            printf("Task was deleted from the list.\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
}
void prioritizeTasks(struct Task *temp)
{
    int j=0;
    int arr[20];
    printf("Here ");
    while(temp!=NULL)
    {
        arr[j]=temp->priority;
        j++;
        temp=temp->next;
    }
    int n=j,c;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                c=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=c;
            }
        }
    }
    printf("\nThe priority list is ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int searchTask(int t,struct Task *temp)
{
    int f=0;
    int position = 1;
    if(temp==NULL)
    {
        printf("No tasks to search from ");
        return -1;
    }
    while (temp!= NULL) 
    {
        if (temp->taskId==t)
        {
            return position;
        }
        temp=temp->next;
        position++;
    }
    
    printf("Task not found in the list.\n");
    return -1;
}
int main()
{
    struct Task *head;
    head=NULL;
    struct Task *one,*two=NULL;
    one=malloc(sizeof(struct Task));
    two=malloc(sizeof(struct Task));
    one->taskId=12;
    strcpy(one->description,"Manager");
    one->priority=6;
    two->taskId=13;
    strcpy(two->description,"Hard");
    two->priority=5;
    one->next=two;
    two->next=NULL;
    head=one;
    int ch=3;
    while(ch!=6)
    {
        printf("\nEnter 1 to add a task ");
        printf("\nEnter 2 to delete a task ");
        printf("\nEnter 3 to display all the tasks ");
        printf("\nEnter 4 to prioritize tasks "); 
        printf("\nEnter 5 to search for a task ");
        printf("\nEnter 6 to exit ");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int t,p;
                char a[20];
                printf("Enter the task id ");
                scanf("%d",&t);
                printf("Enter the task description ");
                scanf(" %[^\n]",a);
                printf("Enter the priority ");
                scanf("%d",&p);
                addTask(t,a,p,head);
                displayTasks(head);
                break;
            }
            case 2:
            {
                int t;
                printf("Enter the task id of the task that has to be deleted ");
                scanf("%d",&t);
                deleteTask(t,head);
                displayTasks(head);
                break;
            }
            case 3:
            {
                displayTasks(head);   
                break;
            }
            case 4:
            {
                prioritizeTasks(head);
                break;
            }
            case 5:
            {
                int t,k;
                printf("Enter the task id of the task that has to be searched ");
                scanf("%d",&t);
                k=searchTask(t,head);
                printf("It is found in the position %d ",k);
            }
            case 6:
            {
                printf("Bye");
                break;
            }
            default:
            {
                printf("Wrong Input");
                break;
            }  
        }
    }
}