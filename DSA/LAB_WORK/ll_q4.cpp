// reverse linked list
#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
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
    void insert(int v){
        Node* new_node = new Node(v);
        if(head==NULL){head=new_node; return;}
        Node* t = head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next = new_node;
    }

    void display_list(){
        Node* t = head;
        while(t!=NULL){
            cout<<t->value<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    // void reverse(){
    //     Node* t = head;
    //     while(t!=NULL){
    //         s.push(t->value);
    //         t=t->next;
    //     }

    //     t = head;
    //     while(t!=NULL){
    //         t->value = s.top();
    //         s.pop();
    //         t=t->next;
    //     }
    // }

    void reverse(){
        Node* p = NULL;
        Node* temp = head;
        Node* front;
        while(temp!=NULL){
            front = temp->next;
            temp->next = p;
            p= temp;
            temp = front;
        }
    }
};
int main(){
    List list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(60);
    cout<<"original:\n";
    list.display_list();
    list.reverse();
    cout<<"reversed:\n";
    list.display_list();
}