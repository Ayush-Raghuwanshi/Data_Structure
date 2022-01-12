#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack{
    int top;
    int capacity;
    int *arr;
};

struct stack* CreateStack(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    if(!s){
        free(s);
        return NULL;
    }
    s->top=-1;
    s->capacity=1;
    s->arr=(int*)malloc(s->capacity * sizeof(int));
    if(!s->arr) return NULL;
    return s;
}
void doubleStack(struct stack* s){
    s->capacity*=2;
    struct stack* temp=realloc(s->arr,s->capacity*sizeof(int));
    if(temp==NULL){
        doubleStack(s);
    }
    else{
        s=temp;
    }
}
int isEmptyStack(struct stack *s){
    return s->top==-1;
}

int isFullStack(struct stack *s){
    return s->top==s->capacity-1;
}

void push(struct stack *s,int data){
    if(isFullStack(s)){
        doubleStack(s);
        
    }
       s->arr[++s->top]=data;
    
}

int pop(struct stack *s){
    if(isEmptyStack(s)){
        return INT_MIN;
    }
    else{
        return s->arr[s->top--];
    }
}

void deleteStack(struct stack *s){
    if(s)
        if(s->arr){
            free(s->arr);
        }
        free(s);
}
int main(){
    struct stack *s= CreateStack();
    push(s,0);
    push(s,1);
    printf("%d\n",pop(s));
    push(s,3);
    push(s,6);
    push(s,6);
    push(s,9);
    push(s,6);
    push(s,6);
    push(s,9);
    push(s,6);
    push(s,6);
    push(s,9);
    printf("%d\n",pop(s));
    deleteStack(s);
    return 0;
} 