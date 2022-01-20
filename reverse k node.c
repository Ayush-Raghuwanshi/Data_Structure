

    struct node* reverseList(struct node *head)  //reversing the list
    {
        struct node *prev=head,*curr=head->next,*prevp=NULL;
        while(curr){
            prev->next=prevp;
            prevp=prev;
            prev=curr;
            curr=curr->next;
        }
        prev->next=prevp;
        return prev;
    }
    
    struct node* retptr(struct node* head,int k){    // traversing into list k times
        struct node* curr=head;
        k--;
        while(k--){
            if(!curr->next)
                return curr;
            curr=curr->next;
        }
        return curr;
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        struct node *headptr1=head,*curr=head,*k2=head,*headptr2=head;
        int p=1;
        while(k2){
            curr=retptr(headptr2,k);
            k2=curr->next;
            curr->next=NULL;
            if(p==1){
                head=curr;
                reverseList(headptr2);}
            else{
                headptr1->next=reverseList(headptr2);
                headptr1=headptr2;}
            p=2;
            headptr2=k2;
        }
        return head;
    }

  

