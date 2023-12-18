#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left,*right;
};
 void main()
{
struct node*insert(struct node*,int);
struct node*delete(struct node*,int);
struct node*search(struct node*,int);
int option,item,ans,data;
struct node*dl=(struct node*)0,*t;
do
{
printf("\n1. Insert \n");
printf("\n2.Delete \n");
printf("\n3.Search \n");
printf("\n4.Exit \n");
printf("Option \n");
scanf("%d",&option);
switch(option)
{
case 1: printf("Data:");
        scanf("%d",&data);
        dl=insert(dl,data);
        break;
case 2:printf("Item:");
       scanf("%d",&data);
       dl=delete(dl,data);
       break;
case 3:printf("Item:");
       scanf("%d",&data);
       t=search(dl,data);
    
     if(t==(struct node*)0)
       {
       printf("Not Found\n");
       }
       else
       {
       printf("Found");
       }
       break;
case 4:exit(0);
}
}
while(1);
}
//function to insert an item on doubly linked list
struct node*insert(struct node*dl,int item)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=item;
t->left=(struct node*)0;
t->right=dl;
if(dl!=(struct node*)0)
dl->left=t;
return t;
}

//fn to search an item
struct node*search(struct node *dl,int item)
{
while(dl!=(struct node*)0 && dl->data!=item)
dl=dl->right;
return dl;
}

//fn to delete an item
struct node*delete(struct node*dl,int item)
{
struct node*t;
t=search(dl,item);
if(t==(struct node*)0)
printf("Not found\n");
else
{
if(t->left==0 && t->right==0)
dl=(struct node*)0;
else if(t->left==(struct node*)0)
{
t->right->left=t->left;
dl=dl->right;
}
else if(t->right==(struct node*)0)
{
t->left->right=t->right;
}
else
{
t->left->right=t->right;
t->right->left=t->left;
}
free(t);
printf("\n %d deleted \n",item);
}
return dl;
}

