#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct song{
    char title[50];
    char artist[20];
    struct song *next;
};

void displayPlaylist(struct song *temp)
{
    while(temp!=NULL)
    {
        printf("\nThe name of the song is %s",temp->title);
        printf("\nThe name of the artist is %s",temp->artist);
        temp=temp->next;
        printf("\n");
    }
}

void addSong(char titl[],char artis[],struct song *temp)
{
    struct song *new=NULL;
    new=malloc(sizeof(struct song));
    strcpy(new->title,titl);
    strcpy(new->artist,artis);
    new->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
 }
 // Function to delete a song from the playlist
void deleteSong(char title[],struct song *temp) {
    if (temp==NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct song* prev=NULL;
    while (temp!=NULL) {
        if(strcmp(temp->title, title)==0) 
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
            printf("Song '%s' deleted from the playlist.\n", title);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    
    printf("Song '%s' not found in the playlist.\n", title);
}


void playPlaylist(struct song *temp)
{
    printf("\nThe songs will be played in the order of:- ");
    while(temp!=NULL)
    {
        printf("\n%s ",temp->title);
        temp=temp->next;
    }
}

int searchSong(char title[],struct song *temp)
 {
    if (temp== NULL) {
        printf("Playlist is empty.\n");
        return -1;
    }
    int position = 1;
    while (temp!= NULL) 
    {
        if (strcmp(temp->title, title) == 0)
        {
            return position;
        }
        temp=temp->next;
        position++;
    }
    
    printf("Song '%s' not found in the playlist.\n", title);
    return -1;
}
int main()
{
    char t[50],tit[20],art[20],a[20],su[50];
    int k;
    char ti[50];
    //initialsing some default data
    struct song *head;
    struct song *one=NULL;
    struct song *two=NULL;
//memory allocation of default data
    one=malloc(sizeof(struct song));
    two=malloc(sizeof(struct song));
    char c[50]="exile";
//copying it on to the nodes 
    strcpy(one->title,c);
    strcpy(one->artist,"Taylor Swift");
    strcpy(two->title,"lehrein");
    strcpy(two->artist,"Amit Trivedi");
//connecting the nodes
    one->next=two;
    two->next=NULL;
//giving head a value
    head=one;
    int ch=3;
    while(ch!=6)
    {
        printf("\nEnter 1 to insert a song to the playlist");
        printf("\nEnter 2 to delete a song from the playlist");
        printf("\nEnter 3 to display the playlist");
        printf("\nEnter 4 to play the playlist"); 
        printf("\nEnter 5 to search a song");
        printf("\nEnter 6 to exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("\nEnter the name of the song to be added ");
                scanf(" %[^\n]",t);
                printf("\nEnter the artists name to be added ");
                scanf(" %[^\n]",a);
                addSong(t,a,head);
                displayPlaylist(head);
                break;
            }
            case 2:
            {
                printf("Enter the title of the song to be deleted ");
                scanf("%[^\n]c",ti);
                deleteSong(ti,head);
                displayPlaylist(head);
                break;
            }
            case 3:
            {
                displayPlaylist(head);
                break;
            }
            case 4:
            {
                playPlaylist(head);
                break;
            }
            case 5:
            {
                printf("\nEnter the title of the song to be searched ");
                scanf("%[^\n]c",su);
                k=searchSong(su,head);
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
