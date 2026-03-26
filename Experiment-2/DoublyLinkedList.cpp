#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int value){
        val = value;
        next = nullptr;
        prev = nullptr;
    }
};
class doublylinkedList{
    private:
    Node* head;
    public:
    doublylinkedList(){
        head = nullptr;
    }
    void inserAtTheEnd(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void inserAtTheStart(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void deleteByValue(int val){
        if(head==nullptr){
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            if(temp->val == val){
                if(temp->prev!=nullptr){
                    temp->prev->next = temp->next;
                }else{
                    head = temp->next;
                }
                if(temp->next!=nullptr){
                    temp->next->prev = temp->prev;
                }
                return;
            }
            temp = temp->next;
        }
    }
    void deleteByPosition(int pos){
        if(head==nullptr || pos<0){
            return;
        }
        Node* temp = head;
        int currPos = 0;
        while(temp!=nullptr){
            if(currPos == pos){
                if(temp->prev!=nullptr){
                    temp->prev->next = temp->next;
                }else{
                    head = temp->next;
                }
                if(temp->next!=nullptr){
                    temp->next->prev = temp->prev;
                }
                return;
            }
            temp = temp->next;
            currPos++;
        }
    }
    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<" <-> ";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};
int main(){
    doublylinkedList dll;
    dll.inserAtTheEnd(10);
    dll.inserAtTheEnd(20);
    dll.inserAtTheEnd(30);
    dll.display();
    dll.inserAtTheStart(5);
    dll.display();
    dll.deleteByValue(20);
    dll.display();
    dll.deleteByPosition(1);
    dll.display();
    return 0;
}