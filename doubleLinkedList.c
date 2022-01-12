#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void traverse(struct node* head){
    struct node* current=head;
    int c=1;
    while (current!= NULL){
        printf("node %d: %d \n",c++,current->data);
        current=current->next;
    }
}

void shift(struct node* head,int data){
    struct node* temp =NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = head->data;
    temp->next = head->next;
    head->data = data;
    head->next = temp;
    head->prev=NULL;
    temp->prev = head;
}

int pop(struct node* head){
    struct node* curr=head;
    while(curr->next){
        curr=curr->next;
    }
    int c= curr->data;
    struct node* temp=curr->prev;
    temp->next=NULL;
    free(curr);
    return c;
}

void append(struct node* head, int data){
    struct node *current= head;
    while(current->next!=NULL){
        current=current->next;
    }
    struct node* newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode-> data = data;
    current-> next= newnode;
    newnode-> next=NULL;  
    newnode->prev= current;
}

void insert(struct node* head,int i,int d){
    struct node* curr=head;
    struct node* temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    for(int j=0;j<i;j++){
        curr=curr->next;
    }    
    struct node* nextnode=curr->next;
    curr->next=temp;
    temp->next=nextnode;
    temp->prev=curr;
}

void removell(struct node* head,int i){
    struct node* curr=head;
    for(int j=0;j<i;j++){
        curr=curr->next;
    }
    curr->prev->next=curr->next;
    free(curr);
  /*
    head=curr->next;
    head->next=curr->next->next;
    free(curr->next);*/
    
}

void deleteLinkedlist(struct node* head){
    struct node* curr=head->next;
    while (curr){        
        free(curr->prev);
        curr=curr->next;
    }
}
struct node* rev(struct node* head){
    struct node *curr=head->next;
    struct node *prev=head;
    struct node *temp=NULL;

    while(curr!=NULL){
        prev->next=temp;
        temp=prev;
        prev=curr;
        curr=curr->next;
    }
    prev->next=temp;
    return prev;
}
void main(){
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
 
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    
    head->data=1;
    head->next=second;
    head->prev=NULL;

    second->data=2;
    second->next=third;
    second->prev=head;

    third->data=3;
    third->next= NULL;
    third->prev= second;

    traverse(head);
    append(head,4);
    traverse(head);

    shift(head,0);
    traverse(head);

    printf("%d \n",pop(head));
    traverse(head);

    removell(head,3);
    traverse(head);

    insert(head,1,10);
    traverse(head);
    printfromend(head);

    deleteLinkedlist(head);

    head = (struct node*)malloc(sizeof(struct node));   
    head->data=100;
    head->next=NULL;
    head->prev=NULL;
    
    traverse(head);
}