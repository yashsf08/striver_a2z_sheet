#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'


const int MOD = 1e9 + 7;
const ll INF = 1e18;


class Node {
  public:
  int data;
  Node* next;
  Node(int data) {
    this -> data = data;
    this -> next = NULL;
  }

  //TODO
  ~Node() {
    int value = this->data;
    this->next = NULL; 
    cout << "Memory is free for node with data " << value << endl;  
  }

};

// Traversing
void printNodes(Node* &head) {
  Node* temp = head;
  if (temp == NULL) cout << "LL is empty!!!" << endl;
  while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int getLength(Node* &head) {
  Node* temp = head;
  int cnt = 0;

  while (temp != NULL) {
    cnt++;
    temp = temp->next;
  }

  return cnt;
}

// Insertion
void insertAtHead(Node* &head, Node* &tail, int d) {
  Node* temp = new Node(d);
  // when LL is empty
  if (head == NULL) {
    head = temp;
    tail = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}
void insertAtTail(Node* &head, Node* &tail, int d) {
  Node* temp = new Node(d);
  // when LL is empty
  if (head == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
  // when LL is empty
  if (head == NULL) {
    Node* temp = new Node(d);
    head = temp;
    tail = temp;
    return;
  }

  // when inserting at Head
  if (position == 1) {
    insertAtHead(head, tail, d);
    return;
  }

  Node* prev = head;
  Node* curr = head->next;

  int cnt = 1;

  while (cnt != position - 1) {
    if (curr == NULL) {
      cout << "Segmentation Error" << endl;
      return;
    }
    prev = curr;
    curr = curr->next;
    cnt++;
  }

  Node* temp = new Node(d);
  temp->next = prev->next;
  prev->next = temp;

  if (temp->next == NULL) {
    tail = temp;
  }

  return;
}

// Deletion

// deletion at Head
int deleteAtHead(Node* &head, Node* &tail) {
  int val = -1;
  // list is empty
  if (head == NULL) {
    cout << "List is empty!" << endl;
    return val;
  }

  Node* temp = head;
  val = head->data;
  if (head->next == NULL){
    head = tail = NULL;
  } else {
    head = head->next;
  }
  delete temp;
  return val;
}

// deletion at position
int deleteAtPosition(Node* &head, Node* &tail, int position) {

  // if list if empty or only has one element
  if (head == NULL) {
    cout << "List is empty!" << endl;
    return -1;    
  }

  // providing invalid arguments
  if (position <= 0) {
    cout << "Invalid positon" << endl;
    return -1;
  }

  if (position == 1) {
    return deleteAtHead(head, tail);
  } 

  Node* prev = NULL;
  Node* curr = head;
  int cnt=1;

  while (cnt < position && curr != NULL) {
    prev = curr;
    curr = curr->next;
    cnt++;
  }

  if (curr == NULL) {
    cout << "Position is out of bounds!!" << endl;
    return -1;
  }

  int val = curr->data;
  prev->next = curr->next;

  if (prev->next == NULL) {
    tail = prev;
  }

  curr->next = NULL;
  delete curr;

  return val;
}



// [Optional] deletion at tail

// emptying the List
void deleteList(Node* &head, Node* &tail) {
  Node* curr = head;
  while (curr != NULL) {
    Node* nextNode = curr->next;
    delete curr;
    curr = nextNode;
  }
  head = NULL;
  tail = NULL;
}

int main() {

  Node* head = new Node(50);
  Node* tail = head;

  cout << "The LL size is : " << getLength(head) << endl;

  insertAtHead(head, tail, 40);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  insertAtTail(head, tail, 25);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;


  insertAtPosition(head, tail, 4, 30);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  insertAtPosition(head, tail, 3, 75);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  insertAtPosition(head, tail, 9, 80);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  // deleteList(head, tail);
  // printNodes(head);

  deleteAtHead(head, tail);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  deleteAtPosition(head, tail, 1);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  deleteAtPosition(head, tail, 3);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  return 0;
}