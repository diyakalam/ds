#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node * next;
};
void main()
{
struct node*sp=(struct node*)0;//empty stack
struct node*push(struct node*,int);
struct node*pop(struct node*,int *);
int search(struct node*,int);
int option,item,ans;
do
{
printf("\n 1. Push \n");
printf("\n 2. Pop \n");
printf("\n 3. Search \n");
printf("\n 4. Exit \n");
printf("Option:");
scanf("%d", &option);
switch (option)
{
      case 1: printf("Data:");
              scanf("%d",&item);
              sp=push(sp,item);
              break;
      case 2:if(sp==(struct node*)0)
             printf("Stack empty");
              else 
             {
             sp=pop(sp,&item);
             printf("Popped item=%d\n",item);
             }
             break;
      case 3:printf("Data:");
             scanf("%d",&item);
             ans=search(sp,item);
             if(ans!=0)
             printf("Found\n");
             else 
             printf("Not found\n");
             break;
      case 4:exit(0);
}
}
while(1);
}
//function to push an item in linked stack
struct node*push(struct node*sp,int data)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
t->next=sp;
return t;
}
//function to pop an element
struct node*pop(struct node*sp,int *data)
{
struct node*t=sp;
if(sp!=(struct node*)0)
{
*data=sp->data;
sp=sp->next;
free(t);
}
return sp;
}
//function to search an item
int search(struct node*sp,int data)
{
while(sp!=(struct node*)0 && sp->data!=data)
sp=sp->next;
if(sp==(struct node*)0)
return 0;
else
return 1;
}
