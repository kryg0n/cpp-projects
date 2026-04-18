#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor = auto function when an onject is created
    Node(int passedData) {
        this->data = passedData;
        this->next = NULL;
    }
};

//insert at head function
    void InsertAtHead(int newData, Node* &Head){
        // why use reference for head -> we want to change orignal list

        //new node creation
        Node * temp = new Node(newData);
        // point to old head
        temp->next = Head;
        // make this new head
        Head = temp;
    };

// traverse/read a list
void printList(Node* &Head) {
    //start printin sll
    cout<<"list:"<<endl;
    //new node created and store head
    Node* temp = Head;
    //keep printing till null
    while(temp!=NULL) {
        //print node
        cout<<temp->data<<" "<<temp->next<<endl;
        // temp will become temp ka next
        temp = temp->next;

    };
};

//insert at Tail
void insertAtTail(int newData, Node* &Tail) {
    // create a new node and store as temp
    Node* temp = new Node(newData);
    //update old tail to have new pointer
    Tail->next= temp;
    //use temp as a tail
    Tail = temp;

};

//insert at position
void insertAtPos(int newData, int Pos) {
    //create a temp
    Node* temp = new Node(newData);

    //trverse till n-1 node
    for()
     

     

};


int main() {

    //create node 
    Node* node1 = new Node(10);

    //print node 1
    cout<<node1->data<<endl<<node1->next<<endl;

    //make the node 1 into head and tail
    Node* head = node1;
    Node* tail = node1;

    //Add node
    InsertAtHead(12, head);

    //print head
    cout<<head->data<<endl<<head->next<<endl;

    //Add node
    InsertAtHead(8, head);

    //Add node at Tail
    insertAtTail(16, tail);


    //print list
    printList(head);



    return 0;
}