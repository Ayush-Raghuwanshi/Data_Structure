#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
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
    temp->data=head->data;
    temp->next=head->next;
    head->data=data;
    head->next= temp;
}
int elementFromEnd(struct node* head,int n){
    struct node* node1=head;
    struct node* node2=head;
    for(int i=0;i<n;i++){
        node1=node1->next;

    }
    while(node1->next!=NULL){
        node2=node2->next;
        node1=node1->next;
    }
    return node2->data;
}


int pop(struct node* head){
    struct node* curr=head;
    struct node* prev=NULL;
    while (curr->next!=NULL)
    {   
        prev=curr;
        curr = curr->next;
    }
    int c= curr->data;
    prev->next=NULL;
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
}

void removell(struct node* head,int i){
    struct node* curr=head;
    struct node* prev=NULL;
    for(int j=0;j<i;j++){
        prev=curr;
        curr=curr->next;
    }
    if(prev){
        prev->next=curr->next;
        free(curr);
    }
    else{
        head=curr->next;
        head->next=curr->next->next;
        free(curr->next);
    }
}





void printfromend(struct node* head){
    if (!head)
    {
        return;
    }
    printfromend(head->next);
    printf("DATA= %d\n",head->data);
}

int iseven(struct node* head){
    struct node* curr=head;
    while (1)
    {
        if (curr==NULL)
            return 1;
        if(curr->next==NULL)
            return 0;
        curr=curr->next;
        curr=curr->next;
    }
    
}

struct node* mergesort(struct node *a,struct node *b){
    struct node* result=NULL;
    if (a==NULL)
    {
        return b;
    }
    if (b==NULL)
    {
        return a;
    }
    if (a->data<b->data){
        result=a;
        result->next=mergesort(a->next,b);
    }
    else{
        result=b;
        result->next=mergesort(a,b->next);
    }
    return result;
}
struct node* swappairs(struct node* head){
    if(head==NULL || head-> next==NULL)
        return head;
    struct node* temp=head->next;
    head->next=temp->next;
    temp->next=head;
    struct node* idk=swappairs(head->next);
    head->next=idk;
    return temp;
}
struct node* reverse(struct node* head){
    struct node* curr=head->next;
    struct node* temp=head;
    struct node* temp2=NULL;
    while(curr){
        temp->next=temp2;
        temp2=temp;
        temp=curr;
        curr=curr->next;
    }
    temp->next=temp2;
    return temp;
}

int ispalindrome(struct node* head){
    struct node* slowptr=head,*fastptr=head;
    while(fastptr->next && fastptr->next->next){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    }
    struct node* head2=slowptr->next;
    slowptr->next=NULL;
    head2=reverse(head2);
    struct node*a=head,*b=head2;
    while(a&&b){
        if(a->data!=b->data){
            head2=reverse(head2);
            slowptr->next=head2;
            return 0;
        }
        a=a->next;
        b=b->next;
    }
    head2=reverse(head2);
    slowptr->next=head2;
    return 1;
}

void revpair(struct node* head,int k){
    struct node* headptr;
    struct node* temp;
    struct node* knext=head;
    struct node* temp2;
    headptr=head;
    while(1){
    knext=headptr;
    struct node* curr=knext;
    for(int i=0;i<k-1;i++){
        if(curr){
            curr=curr->next;
        }
        else{
            return;
        }
    }
    knext=curr->next;
    curr->next=NULL;
    
    temp=reverse(headptr);

    knext->next=temp;
    
    headptr=knext;
    knext=curr->next;
}
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

    second->data=2;
    second->next=third;

    third->data=3;
    third->next= NULL;
    
    traverse(head);
    append(head,4);
    traverse(head);

    shift(head,0);
    traverse(head);

    printf("%d \n",pop(head));
    traverse(head);

    removell(head,3);
    traverse(head);

    insert(head,2,10);
    traverse(head);

    printf("%d \n",elementFromEnd(head,1));
    traverse(head);
    
    traverse(head);
    printfromend(head);

    printf("\n%d\n",iseven(head));
    struct node* head2=NULL;
    struct node* second2=NULL;
    struct node* third2=NULL;

    head2=(struct node*)malloc(sizeof(struct node));
    second2=(struct node*)malloc(sizeof(struct node));
    third2=(struct node*)malloc(sizeof(struct node));
    head2->data=3;
    head2->next=second2;
    second2->data=6;
    second2->next=third2;
    third2->data=9;
    third2->next=NULL;
    
    head = mergesort(head,head2);

    traverse(head);
    head=swappairs(head);
    printf("\n");
    traverse(head);

    head=reverse(head);
    traverse(head);
    
   
    
    printf("\n%d\n",ispalindrome(head));
    traverse(head);

    revpair(head,3);

}