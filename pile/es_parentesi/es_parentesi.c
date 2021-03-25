#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct el{
    char valore;
    struct el* next;
}El;

int is_empty(El* head){
    
    if (head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(struct El **head, struct El *element){
    if (is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct El *pop(struct El **head){
    struct El *ret = *head;
    if(is_empty(*head)){
        return NULL ;
    }else{
        *head = ret->next;
    }
    return ret;
}

bool isParentesiAperta(char car){
    if (car == '(' || car == '[' || car == '{')
    {
        return true;
    }else{
        return false;
    }
    
}

bool isParentesiChiusa(char car){
    if (car == ')' || car == ']' || car == '}')
    {
        return true;
    }else{
        return false;
    }
    
}

bool verificaParentesi(El *stringa, El *pila, El *element){
    bool ok = true;
    int cnt = 0;
    while(cnt < strlen(stringa) && ok == true){
        if (isParentesiAperta(*(stringa+cnt)))
        {
            element->valore = *(stringa+cnt);
            push(&pila,element);
        }

        if (isParentesiChiusa(*(stringa+cnt)))
        {
            if(*(stringa+cnt) == ')' && pop(&pila)->valore != '('){
                ok = false;
            }
            if(*(stringa+cnt) == ']' && pop(&pila)->valore != '['){
                ok = false;
            }
            if(*(stringa+cnt) == '}' && pop(&pila)->valore != '{'){
                ok = false;
            }
        }
        cnt++;
        
    }
    return ok;
}


int main(){
    char *stringa;
    printf("inserisci la stringa di prentesi: ")
    scanf("%s", stringa);
    El *pila = (El*)malloc(sizeof(El));
    El *element = (El*)malloc(sizeof(El));

    if(verificaParentesi(stringa,pila,element) == true){
        printf("\nla sequenza è giusta");
    }else{
        printf("\nla sequenza è sbagliata");
    }

}