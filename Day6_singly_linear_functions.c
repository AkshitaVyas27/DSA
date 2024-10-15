#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

int count_node(void);
struct node * create_node(void);
struct node* add_pos(int data, int pos);
void add_first(int data);
void add_last(int data);
void delete_first();
void delete_last();
struct node* delete_pos(int pos);
void display();
void selection_sort();
struct node * linear_search(int key);
void reverse_list(void);
struct node* find_mid(void);


struct node *head=NULL;
int main(){

add_first(10);
    add_first(20);
    add_first(30);
 
   add_last(40);
    add_last(60);
    add_first(50);
    add_last(80);
    add_first(70);
    add_first(100);
    display();
    
   
   add_pos(150,6);
  
   display();
   delete_first();
  display();
  
   delete_last();
   display();
 
   delete_pos(4);
   add_first(10);
    add_first(20);
    add_first(30);
 
   add_last(40);
    add_last(60);
    add_first(50);
    add_last(80);
    add_first(70);
    add_first(100);
    display();
    struct node* mid=find_mid();
    printf("the mid is at %d", mid);
   display();
   reverse_list();
   display();
   selection_sort();
   display();
   
   int key1;
   printf("enter key:\n");

   scanf("%d", &key1);
   
    struct node* key=linear_search(key1);
   if(key==NULL)
   printf("key not found");
 else
  printf("key found at %u", key);
    return 0;




}

int count_node(void){
    int count=0;
    if(head==NULL){
        printf("List is empty");
    }
    else{
        struct node* trav=head;
        while(trav!=NULL){
            count++;
            trav=trav->next;
        }
    }
    return count;
}

struct node* create_node(void)
{
struct node* ptr = (struct node *)malloc(sizeof(struct node));
ptr->data=0;
ptr->next=NULL;
return ptr;
}


void add_first(int data){
    struct node *ptr=create_node();
    ptr->data=data;
    if(head==NULL){
    head=ptr;   
    }
    else
    { 
        ptr->next=head;
        head=ptr;
    }
}

void add_last(int data){
     struct node *ptr=create_node();
    ptr->data=data;
    if(head==NULL){
        head=ptr;
    }
   
    else{ 
        struct node*trav=head;
        while(trav->next!=NULL){
            trav=trav->next;
        }
        trav->next=ptr;

    }
}

struct node* add_pos(int data, int pos){
    

    if(head==NULL){
        if(pos==1)
        add_first(data);
        else
        printf("Invalid position");


    }

    else if(pos<0||pos>count_node()+1)
    printf("Invalid position");

    else if(pos==1){
        add_first(data);
    }
    else if(pos==count_node()+1)
    add_last(data);

    else{
    struct node *ptr=create_node();
    ptr->data=data;
        struct node*trav=head;
        for(int i=1;i<pos-1;i++){
            trav=trav->next;
        }
        ptr->next=trav->next;
        trav->next=ptr;
    }
}

void delete_first(){
    if(head==NULL){
        printf("List is empty");
    }
        else if(head->next=NULL){
            free(head);
            head=NULL;
        }


        else{
            struct node* temp=head;
            head=head->next;
            free(temp);
            temp=NULL;
        }

        }
    
void delete_last(){
    if(head==NULL){
        printf("List is empty");
    }
        else if(head->next=NULL){
            free(head);
            head=NULL;
        }


        else{
            struct node*trav=head;
            while(trav->next->next!=NULL){
                trav=trav->next;
            }
            free(trav->next);
            trav->next=NULL;

}
}

struct node* delete_pos(int pos){
   
   

    if(head==NULL){
        printf("List is empty");

    }

    else if(pos<1||pos>count_node())
    printf("Invalid position");

    else if(pos==1){
        delete_first();
    }
    else if(pos==count_node())
    delete_last();

    else{
    struct node * trav=head;
    int i;
    for(i=1; i<pos-1;i++){
        trav=trav->next;
    }
    struct node *temp=trav->next;
    trav->next=temp->next;
    free(temp);
    temp=NULL;

    }
}
void display(){
    if(head==NULL){
        printf("List is empty");
    }
        else{
            struct node * trav=head;
            while(trav!=NULL)
            {
            printf("->%d",trav->data);
            trav=trav->next;
            }
        }
        printf("\n");
    }


void selection_sort(){
    struct node *i, *j;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

}



struct node * linear_search(int key){
    struct node *i;
    for(i=head;i!=NULL;i=i->next){
        if(i->data==key){
            return i;
        }
    }
        return NULL;
    

}



void reverse_list(void){
    struct node* n1=head;
    struct node* n2=head->next;

    while(n2!=NULL){
        struct node* n3=n2->next;
        n2->next=n1;
        n1=n2;
        n2=n3;
    }
    head->next=NULL;
    head=n1;
}



struct node* find_mid(){
    struct node* fast=head;
    struct node* slow=head;


    do{
        fast=fast->next->next;
        slow=slow->next;
        if(fast==NULL)
        break;
    }while(fast->next!=NULL);
    return slow;
}