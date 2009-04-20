#include <string.h>

typedef struct node{
    char name[30];
    struct node *l,*r;
}Tree;

print(Tree*T,int d){
    int i;
    if(T){
    for(i=0;i<d;++i)printf("+");
        printf("%s\n",T->name);
        print(T->l,d+1);
        print(T->r,d);
    }
}

Tree *r,*temT;
find(Tree*T,char name[])
{
    int i;
    if(T){
        if(T->l && strcmp(T->l->name,name)==0){
            r=T;temT=T->l;
            return;
        }
        else if(T->r && strcmp(T->r->name,name)==0){
            r=T;temT=T->r;
            return;
        }
            find(T->l,name);
            find(T->r,name);
    }
}

hire(Tree *T,char name1[],char name2[]){
    Tree *newNode,*p;
    p=temT=r=T;
    find(T,name1);
    if(temT->l!=NULL){
        temT=temT->l;
        while(temT->r!=NULL)temT=temT->r;

        newNode=(Tree*)malloc(sizeof(Tree));
        if(newNode!=NULL){
            strcpy(newNode->name,name2);
            temT->r=newNode;
            newNode->l=newNode->r=NULL;
        }
    }else{
        newNode=(Tree*)malloc(sizeof(Tree));
        strcpy(newNode->name,name2);
        temT->l=newNode;
        newNode->l=newNode->r=NULL;
    }
}

fire(Tree*T,char name[]){
    Tree *newNode,*p;
    p=temT=r=T;
    find(T,name);

    while(temT->l!=NULL){
        strcpy(temT->name,temT->l->name);
        r=temT;
        temT=temT->l;
    }
    if(temT->l==NULL && temT->r==NULL){
        if(r->l==temT) r->l=NULL;
        else if(r->r==temT) r->r=NULL;
        free(temT);
    }else if(temT->l==NULL && temT->r!=NULL){
        if(r->l==temT) r->l=temT->r;
        else if(r->r==temT) r->r=temT->r;
        free(temT);
    }
}

main(i){
    char cmd[99],arg0[20],arg1[20],arg2[20];
    Tree *root;
    root=(Tree*)malloc(sizeof(Tree));
    gets(root->name);
    root->l=root->r=NULL;

    for(;gets(cmd);){
        switch(sscanf(cmd,"%s%s%s",arg0,arg1,arg2)){
            case 1:
                print(root,0);
                puts("------------------------------------------------------------");
                break;
            case 2:
                fire(root,arg1);
                break;
            case 3:
                hire(root,arg0,arg2);
                break;
        }
    }
}
