#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;




void insertAtHead(){
    struct node* ptr;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
      ptr->data=data;
      ptr->next=NULL;
      head=ptr;
    }
    else{
        struct node* temp;
        temp=head;
        ptr->data=data;
        ptr->next=head;
        head=ptr;
    }

}



void insertAtTail(){
struct node* ptr;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
      ptr->data=data;
      ptr->next=NULL;
      head=ptr;
    }
    else {
        struct node* temp;
        temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        ptr->data=data;
        ptr->next=NULL;
        temp->next=ptr;

    }
}


void insertAtAnyposition(){
struct node* ptr;
    int data,pos,count=1;
    printf("Enter the data : ");
    scanf("%d",&data);
    printf("Enter the position to insert ");
    scanf("%d",&pos);
    ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
     printf(" The list is empty ");
    }
    else{
        struct node* temp;
        temp=head;

     while(temp->next!=NULL&&count<pos-1)
     {
        count++;
        temp=temp->next;
     }

     ptr->data=data;
     ptr->next=temp->next;
     temp->next=ptr;
     
    }
}



void DeleteAtHead()
{
    struct node* temp;
    temp=head;
    head=temp->next;
    free(temp);

}

void DeleteAtTail()
{
    struct node* temp;
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;

}

void DeleteAtAnyPosition()
{
    struct node *temp,*temprv;
    int pos,count=1;
        printf("enter the postion: ");
		scanf("%d",&pos);
        if(pos==1){
            DeleteAtHead();
        }
        else{
            
           temp=head;
           while (temp->next!=NULL&&count<pos)
           {
               count++;
               temprv=temp;
               temp=temp->next;
           }
           if(count==pos)
           {
               temprv->next=temp->next;
               free(temp);
           }
        }
}


void display(){
    struct node* temp;
    temp=head;  // to reverse the order we just need to insert tail here
    while (temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    
    
}

void findElement()
{
    struct node* temp;
    int data,count=1;
    if(head==NULL)
    { printf("First create the list ");}
    else{
       temp=head;
       printf("Enter the data element : ");
       scanf("%d",&data);
        while (temp->data!=data)
        {
            
              temp=temp->next;
              count++;
        }
        if(temp->data==data)
               printf("%d",count);
        
    }
}


void reverseElement()
{
    struct node *temp,*temprv,*curr;
    curr=head;
    temprv=NULL;
    
   while (curr!=NULL)
   {
       temp=curr->next;
       curr->next=temprv;
        temprv=curr;
        curr=temp;
   }
   head=temprv;
   
}

 void reverseUsingRecursion(struct node *ptr)
 {
     struct node *t;
     if(ptr->next==NULL)
     {
         head=ptr;
         return;
     }
     reverseUsingRecursion(ptr->next);
     struct node *q=ptr->next;
     q->next=ptr;
     ptr->next=NULL;
 }

 void traverseUsingRecursion(struct node* ptr)
 {
     if(ptr->next==NULL){
         printf(" %d ",ptr->data);
         return;
     }
     traverseUsingRecursion(ptr->next);
     printf(" %d ",ptr->data);

 }

int main(){
    int val;

    while (1)
    {
        
        printf("\n1 insertAtHead()\n2 insertAtTail()\n3 insertAtAnyposition()\n4 DeleteAtHead()\n5 DeleteAtTail(\n6 DeleteAtAnyPosition()\n7 display()\n8 exit() \n9 findElement()\n10 reverse() \n11 reverseUsingRecursion(head)\n");
    scanf("%d",&val);
    switch (val)
    {
    case 1:insertAtHead();
        break;
    case 2:insertAtTail();
        break;
    case 3:insertAtAnyposition();
        break;
    case 4:DeleteAtHead();
        break;
    case 5:DeleteAtTail();
        break;
    case 6:DeleteAtAnyPosition();
        break;
    case 7:display();
        break;
    case 8:exit(0);
        break;
    case 9:findElement();
        break;
    case 10:reverseElement();
        break;
    case 11:reverseUsingRecursion(head);
        break;
    case 12: traverseUsingRecursion(head);
    }
    }

    

    
   
   
    


    return 0;
}