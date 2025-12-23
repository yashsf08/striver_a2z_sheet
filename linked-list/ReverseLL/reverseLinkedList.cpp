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

    Node(int d) {
      this->data = d;
      this->next = nullptr;
    }

    ~Node() {
      int val = this->data;
      if (this->next != nullptr) {
        // Node* nextNode = this->next;
        this->next = nullptr;
        // delete nextNode;  //       [Optional]
      }
      cout << "Memory is free for the node with data " << val << endl;
    }
}

void insertAtHead(Node* &head, Node* &tail, int d) {
  Node* newNode = new Node(d);

  if (head == NULL) {
    head = tail = newNode;
    return;
  }

  newNode -> next = head; 
  head = newNode;

  return; 
}

void insertAtTail(Node* &head, Node* &tail, int d) {
	if (head == NULL) {
		insertAtHead(head, tail, d);
		return;
	}

	Node* newNode = new Node(d);
	tail -> next = newNode;
	tail = newNode;
	return;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
  return;
}

// Traersal - utility functions

int getLength(Node* &head) {
  int cnt = 0;
  Node* temp = head;

  while(temp != NULL) {
    cnt++;
    temp = temp -> next;
  }
  return cnt;
}

void printNodes(Node* &head) {
  int cnt = 0;
  Node* temp = head;

  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
  return;
}

// approach I - Iterative
void reverseList(Node* &head, Node* &tail) {
  Node* curr;
  Node* prev;
  Node* next;

  tail = head;
  curr = head;
  prev = nullptr;
  next = nullptr;

  while (curr != nullptr) {
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    head = curr;
    curr = next;
  }

  delete curr;
  delete prev;
  delete next;

  return;
}



// appraoch II
// approach III
//
int main (int argc, char *argv[]) {
  
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

  insertAtHead(head, tail, 20 "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  insertAtHead(head, tail, 35);
  printNodes(head);
  cout << "head: " << head->data << " ";
  cout << "tail: " << tail->data << endl;

  return 0;
}
