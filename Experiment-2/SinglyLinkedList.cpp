#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class Linkedlist{
    private: 
    Node* head;
    
    public:
     Linkedlist(){
        head = nullptr;
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void insertAtStart(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void insertAtMid(int val){
        Node* newNode = new Node(val);
        if(head==nullptr){
            head = newNode;
            return;
        }
        //to find the mid we will use slow and fast pointer
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        newNode->next = slow->next;
        slow->next = newNode;
    }
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("nullptr");
    }
    void deleteNode(int val){
        if(head==nullptr){
            return;
        }
        if(head->data == val){
            head= head->next;
            return;
        }
        Node* temp = head;
        Node* prev;
        if(temp->data == val){
            head = temp->next;
        }
        while(temp!=nullptr){
            if(temp->data==val){
                prev->next = temp->next;
                return;
            }
            prev= temp;
            temp = temp->next;
        }
    }
    void deleteByPosition(int pos){
        if(head==nullptr){
            cout<<"List is Empty!!";
        }
        int currPos = 1;
        Node* temp = head;
        Node* prev;
        while(currPos!=pos){
            prev = temp;
            temp = temp->next;
            currPos++;
        }
        prev->next = temp->next;

    }
};

int main(){
    Linkedlist list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(50);
    list.insertAtEnd(60);
    // list.insertAtMid(40);
    // list.deleteNode(20);
    list.deleteNode(10);

    list.display();
    return 0;
}

//Leetcode - 141
// leetcode -- 141,876,206,147,430