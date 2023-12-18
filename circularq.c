#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE];
int front=0,rear=0;
void main()
{
void enque(int);
int deque();
int search(int);
int option,item,ans;
do
{
printf("\n 1. Insert \n");
printf("\n 2. Delete \n");
printf("\n 3. Search \n");
printf("\n 4. Exit \n");
printf("Option:");
scanf("%d",&option);
switch(option)
{
case 1: printf("Item");
        scanf("%d",&item);
        enque(item);
        break;
case 2:item=deque();
       printf("Item=%d\n",item);
       break;
case 3:printf("Item to search");
       scanf("%d",&item);
       ans=search(item);
       if(ans!=0)
       printf("%d found at %d\n",item,ans);
else
   {
 printf("not found");
}
       break;
case 4:exit(0);
}
}
while(1);
}
// function to insert one item in circular queue
void enque(int item)
{
int t;
t=(rear+1)%SIZE;
if(t==front)
{
printf("Queue is full");
exit(1);
}
else
{
rear=t;
que[rear]=item;
}
}
//function to delete an item
int deque( )
{
if(front==rear)
{
printf("Queue is empty");
exit(2);
}
front=(front+1)%SIZE;
return que[front];
}
//function to search an item in queue
int search(int item)
{
int t1=front,t2=rear;
t1=(t1+1)%SIZE;
while(t1!=t2 && que[t1]!=item)
{
t1=(t1+1)%SIZE;
}
if(front==rear)
{
printf("Queue is empty");
exit(0);
}
if(que[t1]==item)
{
return t1;
}
else
{
return 0;
}
}


