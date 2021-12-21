/*
Write a menu driven program to perform the following operations on linked list.
i) Insert an element in the beginning of the list
ii) Insert an element at the end of the list
iii) Insert an element before another element in the existing list
iv) Insert an element after another element in the existing list
v) Delete a given element from the list
vi) Print the list
*/

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void ins_beg(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    head=n;
}

void ins_end(node*&head,int value){
    node *n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insert_before(node*head, int elem, int value){
    node*temp=new node(elem);
    node*trav=head;
    bool found=false;
    if(trav->data==value){
        head=temp;
        temp->next=trav;
        return;
    }
    while(trav->next!=NULL){
        if(trav->next->data==value){
            temp->next=trav->next;
            trav->next=temp;
            found=true;
            break;
        }
        trav=trav->next;
    }
    if(!found){
        cout<<"Element not found"<<endl;
    }
}

void insert_after(node*head, int elem, int value){
    node*temp=new node(elem);
    node*trav=head;
    bool found=false;
    while(trav!=NULL){
        if(trav->data==value){
            temp->next=trav->next;
            trav->next=temp;
            found=true;
            break;
        }
        trav=trav->next;
    }
    if(!found){
        cout<<"Element not found"<<endl;
    }
}

void del_head(node*&head){
    node* toDel=head;
    head=head->next;
    delete toDel;
}

void del(node*&head,int val){
    if(head==NULL)
    return;
    if(head->next==NULL){
        del_head(head);
        return;
    }
    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node*toDel=temp->next;
    temp->next=temp->next->next;
    delete toDel;
}

void disp(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node*head=NULL;
    int ele,elem;
    while(true){
        cout<<"1. Insert beginning\t2. Insert end\t3. Insert before an element\t4. Insert after an element\t5. Delete an element\t6. Print the list\t7.Exit\n";
        int x;
        cin>>x;
        switch(x){
            case 1:cout<<"Enter the value: "; cin>>ele; ins_beg(head,ele); break;
            case 2:cout<<"Enter the value: ";cin>>ele; ins_end(head,ele); break;
            case 3:cout<<"Enter the element to be added and the element before which it should ne added: "; cin>>elem>>ele; insert_before(head,elem,ele); break;
            case 4:cout<<"Enter the element to be added and the element after which it should ne added: "; cin>>elem>>ele; insert_after(head,elem,ele); break;
            case 5:cout<<"Enter the element to be deleted: "; cin>>ele; del(head, ele); break;
            case 6:disp(head); break;
            case 7:exit(0);
        }
    }
    return 0;
}
