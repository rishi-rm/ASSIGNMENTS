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
    void insert_at_start(int v){
        Node* new_node = new Node(v);
        if(head==NULL){
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;        
    }
    void insert_at_end(int v){
        Node* new_node = new Node(v);
        if(head==NULL){head=new_node; return;}
        Node* t = head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next = new_node;
    }

    void insert_after(int x, int v){
        Node* new_node = new Node(v);

        Node *t = head;
        while (t->value!=x){
            t=t->next;
        }
        new_node->next = t->next;
        t->next = new_node;
    }

    void delete_from_start(){
        if(head==NULL) return;
        Node* t = head->next;
        delete head;
        head = t;
    }

    void delete_from_end(){
        Node *t = head;
        Node *p = head;

        while(t->next!=NULL){
            p=t;
            t=t->next;
        }
        p->next = NULL;
        delete t;
    }

    void delete_at_value(int v){
        if(head->value==v){
            delete_from_start();
            return;
        }
        Node* t = head;
        while(t->next!=NULL){
            t=t->next;
        }

        if(t->value==v){
            delete_from_end();
            return;
        }
        t=head;
        Node* p = head;
        while (t->value!=v){
            p=t;
            t=t->next;
        }
        p->next = t->next;
        delete t;
    }

    int search(int v){
        int pos = 0;
        Node* t = head;
        while(t!=NULL){
            if(t->value==v){
                return pos;
            }
            t=t->next;  
            pos++;
        }
        return -1;
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
    l.insert_at_start(10);
    l.insert_at_start(20);
    l.insert_at_start(30);
    l.insert_at_end(100);
    l.insert_at_end(120);
    l.insert_after(20, 25);
    l.delete_from_start();
    l.delete_from_end();
    l.delete_at_value(10);
    l.insert_at_end(35);
    l.insert_at_end(45);
    l.insert_at_end(65);
    l.insert_at_end(75);
    cout<<l.search(100)<<endl;
    l.display_list();
}