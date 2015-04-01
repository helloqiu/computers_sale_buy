/*
Date : 2015-4-1-12:31
Author : 张宇阳 (heheda || helloqiu)
Description : i finished my c class homework which aims to show buy computers or sale computers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct savecomputer * Computer;

struct savecomputer{
    char *name;
    int num;
    Computer next;
};

static Computer CreateComputer(char *name , int num , Computer from);
Computer FindComputer(Computer from , char * name);
void AddComputer(char *name , int num , Computer from);
void PrintComputer(Computer from);

int main(void)
{
    Computer first = NULL;
    Computer now = NULL;
    while (1){
        printf("please enter the computer name : \n");
        char name[20];
        scanf("%s" , name);
        printf("if this is new please enter 1.else enter 0 : \n");
        int tmp;
        scanf("%d" , &tmp);
        if (tmp){
            if (first == NULL){
                first = CreateComputer(name , 0 , NULL);
                now = first;
            }else{
                CreateComputer(name , 0 , now);
                now = now -> next;
            }
        }
        printf("if you buy it , please enter 1\n");
        scanf("%d" , &tmp);
        printf("please enter the number : \n");
        int num;
        scanf("%d" , &num);
        if (tmp){
            AddComputer(name , num , first);
        }else{
            AddComputer(name , -num , first);
        }
        PrintComputer(first);
    }
    return 0;

}
static Computer CreateComputer(char *name , int num , Computer from){
    Computer computer;
    computer = malloc(sizeof(struct savecomputer));
    computer -> name = malloc(strlen(name));
    strcpy(computer -> name , name);
    computer -> num = num;
    computer -> next = NULL;
    if (from == NULL){
        return computer;
    }
    from -> next = computer;
    return computer;
}

Computer FindComputer(Computer from , char * name){
    if (!strcmp(from -> name , name)){
        return from;
    }
    Computer tmp = from;
    while (strcmp(tmp -> name , name)){
        if (tmp -> next == NULL){
            return tmp;
        }
        tmp = tmp -> next;
    }
    return tmp;
}

void AddComputer(char *name , int num , Computer from){
    Computer tmp = FindComputer(from , name);
    if (tmp == NULL){
        return;
    }
    tmp -> num += num;
}

void PrintComputer(Computer from){
    if (from == NULL){
        return;
    }
    printf("%s has %d\n" , from -> name , from -> num);
    PrintComputer(from -> next);
}


