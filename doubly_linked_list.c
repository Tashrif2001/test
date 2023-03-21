#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*temp;

void insertbegin(int n)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data= n;
    link->next=head;
    head=link;
}
void insert_between(int key, int n)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    int i=1;
    link->data = n;
    temp = head;
    while(i<key)
    {
        temp = temp->next;
        i++;
    }
    link->next= temp->next;
    link->prev = temp;
    temp->next= link;
    temp = temp->next;
    temp->prev =link;
}
void insertlast(int n)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link->data= n;
    link->next= NULL;
    if(head==NULL){
    link->prev= NULL;
    link->next= NULL;
    head=link;
    }
    else{
    temp= head;
    while(temp->next!=NULL)
    temp= temp->next;
    link->prev = temp;
    temp->next= link;
    }
}
void deletefirst()
{
    temp = head;
    head = temp->next;
    temp->prev = NULL;
}
void delete_between(int key)
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    temp = head;
    int i=1;
    while(i<key-1)
    {
        temp = temp->next;
        i++;
    }
    link= temp->next;
    temp->next = link->next;
    link->prev = temp;
}
void deletelast()
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    temp= head;
     while(temp->next!=NULL)
    {
        link= temp;
        temp= temp->next;
    }
    if(temp==head)
    head=NULL;
    else
    link->next= NULL;
    free(temp);
}
void print()
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link= head;
    while(link!=NULL)
    {
        printf("%d ", link->data);
        link= link->next;
    }
}
void printrev()
{
    struct node *link=(struct node*)malloc(sizeof(struct node));
    link = head;
    while(link->next!=NULL)
    link = link->next;
    while(link!=NULL)
    {
        printf("%d ", link->data);
        link = link->prev;
    }
    
}
int main()
{
    insertlast(12);
    insertlast(23);
    insertlast(232);
    insertlast(2);
    insertlast(289);
    delete_between(2);
    print();
    return 0;
}
