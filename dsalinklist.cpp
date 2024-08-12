#include<iostream>
using namespace std ;

class Node {
    public:
    int data ;
    Node* next;
//CONSTRUCTOR
    Node( int data){
      this-> data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node* &head, int d){
    // new node create 
    Node* temp = new Node( d);
    temp->next = head;
    head  = temp;
    

}


void InsertAtTail(Node* &tail,int d){
Node*temp = new Node(d);
tail->next = temp;
tail = temp;

}
void print(Node* &head){
    Node*temp = head;

    while(temp!= NULL ){
        cout<< temp-> data<<" ";
        temp = temp-> next;
    }
cout<<endl;
}
   void InsertAtPosition(Node* &head, int position, int d){
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp-> next;
        cnt++;

    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert ->next =temp-> next;
    temp-> next = nodeToInsert;
    
    
   }


 int main(){
    //created a new node

    Node* node1 = new Node(10);
  // cout<< node1->data <<endl;
  // cout<<node1->next<<endl;

    // head printed to node
    Node* head = node1;
    Node* tail = node1; 
    Node* position = node1;

   print( head);

    InsertAtTail(tail , 12);

    print(tail);
    InsertAtHead(tail, 15);
    print(head);
    InsertAtPosition(position, 3,11);
     print(head);
        


 
cout<<endl;
    return 0;

 
 }