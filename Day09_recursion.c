
#include<stdio.h>
#include<stdlib.h>
struct node* create_node(void);
void add_first(int data);
void inOrder_traverse(struct node* trav);
void add_node_recursive(int data, struct node* trav, struct node* new_node);
void create_new_node_recursion(int data);
struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* root=NULL;

int main(){

create_new_node_recursion(50);
create_new_node_recursion(20);
create_new_node_recursion(90);
create_new_node_recursion(45);
create_new_node_recursion(10);
create_new_node_recursion(5);
create_new_node_recursion(15);
create_new_node_recursion(30);
create_new_node_recursion(85);
create_new_node_recursion(75);
create_new_node_recursion(50);
create_new_node_recursion(100);
create_new_node_recursion(95);
create_new_node_recursion(120);

inOrder_traverse(root);



return 0;
}

struct node* create_node(void){
    struct node* new_node= (struct node*)malloc(sizeof(struct node));
    new_node->right=NULL;
    new_node->left=NULL;
    new_node->data=0;

    return new_node;
}


void add_first(int data){
   struct node* new_node= create_node();
    new_node->data=data;

    if(root==NULL){
        root=new_node;
    }
    else{
        struct node* trav=root;
    while(1){
        if(data<trav->data){
            if(trav->left==NULL){
                trav->left=new_node;
            
                break;
            }
            else
             trav=trav->left;
            
        }
        else{
            
                
            if(trav->right==NULL){
                    trav->right=new_node;
                    break;
            }
            else
             trav=trav->right;
        }
    }
}
}


void inOrder_traverse(struct node* trav){
    if(trav==NULL)
    return;
    inOrder_traverse(trav->left);
    printf("%4d", trav->data);
    inOrder_traverse(trav->right);

}


void add_node_recursive(int data, struct node* trav, struct node* new_node){
    if(trav==NULL){
    trav=new_node;
    return;
    }

    else if(data<trav->data)
    add_node_recursive(data,trav->left,new_node);

    else
    add_node_recursive(data,trav->right,new_node);
}


void create_new_node_recursion(int data){
    struct node* new_node= create_node();
    new_node->data=data;

add_node_recursive(data, root, new_node);

}