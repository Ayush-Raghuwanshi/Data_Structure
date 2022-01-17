#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct stack{
    int top;
    int capacity;
    char *arr;
};
char peek(struct stack* s){
    
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
    s->arr=(char*)malloc(s->capacity * sizeof(char));
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

void infix_to_postfix(char a[]){
    struct stack *s = CreateStack();
    int len=strlen(a);
    for(int i =0;i<=len;i++){
        char ch2=a[i];
        if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')){
            printf("%c",a[i]);
        }
        else if(a[i]==')'){
            while(peek(s)!='('){
                printf("%c",pop(s));
            }
            pop(s);
        }
        else{
            if(a[i]=='*'||a[i]=='/'){
                push(s,a[i]);
            }

            else{
                while(!isEmptyStack(s)&&(peek(s)!='('||peek(s)!='+'||peek(s)!='-')){
                    printf("%c",pop(s));
                }
                push(s,a[i]);
            }
        }
    }
    while(peek(s)){
        printf("%c",pop(s));
    }
}

int main(){
    char s[]="x-y/z-k*d";
    infix_to_postfix(s);
    return 0;
} 