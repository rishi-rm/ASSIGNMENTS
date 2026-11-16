#include<iostream>
using namespace std;
class Node{
    public:
        int value;
        Node *next;

        Node(int v){
            this->value = v;
            this->next = NULL;
        }
};

class List{
    Node *head=NULL;
    public:
    void insert_at_end(int v){
        Node* new_node = new Node(v);
        if(head==NULL){head=new_node; return;}
        Node* t = head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next = new_node;
    }

    int find_mid(){
        Node* t = head;
        int size = 0;
        while (t!=NULL){
            size++;
            t=t->next;
        }

        int mid = size/2;
        t = head;
        int idx = 0;
        while (idx!=mid){
            t=t->next;
            idx++;
        }
        return t->value;
    }

    void display_list(){
        Node* t = head;
        while(t!=NULL){
            cout<<t->value<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};

int main(){
    List l;
    l.insert_at_end(1);
    l.insert_at_end(2);
    l.insert_at_end(3);
    l.insert_at_end(4);
    l.insert_at_end(5);
    cout<<l.find_mid()<<endl;
}