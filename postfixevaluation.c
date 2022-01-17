#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct stack{
    int top;
    int capacity;
    int *arr;
};
int peek(struct stack* s){
    
    return s->arr[s->top];
}
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

int postfixEval(char a[]){
    int k,b;
    struct stack *s= CreateStack();
    for(int i=0;i<strlen(a);i++){
        if(a[i]>='1'&&a[i]<='9'){
            int k=a[i]-48;
            push(s,k);
        }
        else{
            switch(a[i]){
                case '*':
                    push(s,pop(s)*pop(s));
                    break;
                case '/':
                    k=pop(s);
                    b=pop(s);
                    push(s,b/k);
                    break;
                case '+':
                    push(s,pop(s)+pop(s));
                    break;
                case '-':
                    k=pop(s);
                    b= pop(s);
                    push(s,b-k);
                    break;
            }
        }
    }
    return peek(s);
}

int main(){
    char s[]="123*+5-";
    printf("%d",postfixEval(s));
    return 0;
} 