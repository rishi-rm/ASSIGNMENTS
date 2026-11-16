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

    void insert_at_end(int v){
        Node* new_node = new Node(v);
        if(head==NULL){head=new_node; return;}
        Node* t = head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next = new_node;
    }

    int count_occurences(int v){
        Node* t = head;
        int count = 0;
        while(t!=NULL){
            if(t->value == v) count++;
            t=t->next;
        }

        return count;
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
    l.insert_at_end(1);
    l.insert_at_end(2);
    l.insert_at_end(1);
    l.insert_at_end(3);
    l.insert_at_end(1);

    int key;
    cout<<"Enter key: ";
    cin>>key;

    int occurences = l.count_occurences(key);
    cout<<occurences<<endl;

    for(int i = 0; i < occurences; i++){
        l.delete_at_value(key);
    }
    l.display_list();
}