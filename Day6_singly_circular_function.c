#include<stdio.h>
#include<stdlib.h>

struct node* create_node(void);
void add_first(int data);
void display();
struct node* add_last(int data);
struct node* delete_first();
struct node* delete_last();
void add_pos(int data, int pos);
int node_count(void);
void selection_sort();
struct node * linear_search(int key);
void reverse_list(void);
struct node* find_mid(void);


struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;



int main(){
printf("head");
add_first(30);
add_first(20);
add_first(10);
display();
printf("head");
add_last(15);
add_last(20);

display();
struct node* mid=find_mid();
printf("this mid is %d\n", mid);
selection_sort();
display();
reverse_list();
display();
delete_first();
delete_first();
display();
delete_last();
delete_last();
display();
printf("Enter the key");
int key;
scanf("%d", &key);
struct node * addre=linear_search(key);
if(addre==NULL)
    printf("Key not found");
    else
    printf("key found at %u", addre);


    return 0;
}


struct node* create_node(void){

   struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data =0;
    new_node->next=NULL;
    return new_node;

}

void add_first(int data){
struct node* new_node=create_node();
new_node->data = data;
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    else
    {
        struct node* trav=head;
        while(trav->next!=head){
            trav=trav->next;
        }
        new_node->next=head;
        head=new_node;
        trav->next=head;
    }



}

void display(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
    struct node* trav=head;
    do{
        printf("->%d", trav->data);
        trav=trav->next;
    }while(trav!=head);
    }
    printf("\n");

}




struct node* add_last(int data){
    struct node* new_node=create_node();
    new_node->data=data;
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    else{
        struct node* trav=head;
        while(trav->next!=head){
            trav=trav->next;
        }
        trav->next=new_node;
        new_node->next=head;
    }
}

struct node* delete_first(){
    if(head==NULL)
    printf("List is empty");

    else{
        struct node* temp=head;
        struct node* trav=head;
        while(trav->next!=head){
            trav=trav->next;
        }
        head=head->next;
        trav->next=head;
        free(temp);
        temp=NULL;
    }

}

struct node* delete_last(){
    if(head==NULL){
    printf("List is empty\n");
    }
    else{
        struct node* trav=head;
        while(trav->next->next!=head){
            trav=trav->next;
        }
        free(trav->next);
        trav->next=head;
    }




}


void add_pos(int data, int pos){
struct node* new_node=create_node();
    if(head==NULL){
        if(pos==1){
            head=new_node;
        }
        else{
            printf("Invalid");
        }
        
    }
    else if(pos==1){
    add_first(data);
    }
    else if(pos==node_count()+1){
        add_last(data);
    }
}


int node_count(void){
    int count;
    struct node* trav=head;
    do{
        count++;
        trav=trav->next;
    }while(trav!=head);
    return count;
}


void selection_sort(){
    struct node *i, *j;
    for(i=head;i->next!=head;i=i->next){
        for(j=i->next;j!=head;j=j->next){
            if(i->data>j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

}



struct node * linear_search(int key){
    struct node *trav=head;
    do{
    if(trav->data==key){
            return trav;
            trav=trav->next;
        }
    }while(trav!=head);
    
        return NULL;
    

}



void reverse_list(void){
    struct node* n1=head;
    struct node* n2=head->next;

   do{
        struct node* n3=n2->next;
        n2->next=n1;
        n1=n2;
        n2=n3;
    } while(n2!=head);
    head->next=n1;
    head=n1;
}


struct node* find_mid(){
    struct node* fast=head;
    struct node* slow=head;


    do{
        fast=fast->next->next;
        slow=slow->next;
        if(fast==head)
        break;
    }while(fast->next!=head);
    return slow;
}