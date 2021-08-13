#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;

    }

};
void insertattail(node* &head,int val ){
    node* n=new node(val);
    if(head==NULL){
        head=n;
    }else{
        node* temp= head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}
//find out the length of linked list
int  length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
    
}
//we have to find intersection point of these linked list
int intersection(node* &head1,node* &head2){
    int l1=length(head1);//length of 1st node of linkedlist
    int l2=length(head2);//length of 2nd node of linkedlist
    node* ptr1;//lets ptr1 is a node of bigger linkedlist
    node* ptr2;
    int d=0;//create a variable d for difference of length
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;

    }else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }//we use a while loop , we get out of loop after d=0;✔
    while(d!=0){
        ptr1=ptr1->next; 
        if(ptr1==NULL){
            return -1;
        }
        d--;

    } 
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;

        ptr2=ptr2->next;
    }
    return -1;


}//now   we will create intersect function means after which node they are intersecting
//now we are going to intersect two linked list at position pos;
void intersect(node* &head1,node* &head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos!=0){
        temp1=temp1->next;
        pos--;

    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;

    }
    temp2->next=temp1;

}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";

        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertattail(head1,1);
    insertattail(head1,2);
    insertattail(head1,3);
    insertattail(head1,4);
    insertattail(head1,5);
    insertattail(head1,6);
    insertattail(head2,9);
    insertattail(head2,10);  
    display(head1);
    display(head2);
    intersect(head1,head2,3);
    display(head1);
    display(head2);
    cout<<intersection(head1,head2)<<endl;
    return 0;

}