#include <iostream>
#include "Node.cpp"
using namespace std;

class CPrioQueue
{
public:
  int count;
  Node* head;
  Node* tail;

  CPrioQueue();
  CPrioQueue(Node* &ptr);
  void Add(Node* &ptr);
  Node* Remove();
};

CPrioQueue::CPrioQueue():count(0),head(NULL),tail(NULL)
{

}

CPrioQueue::CPrioQueue(Node* &ptr):count(1),tail(ptr),head(ptr)
{
  tail->next = NULL;
  ptr = NULL;
}

void CPrioQueue::Add(Node* &ptr)
{
  if(!head)
  {
    head = tail = ptr;
    tail->next = NULL; // ptr->next is already NULL so why do this??
  }
  else if(ptr->priority > head->priority)
  {
    ptr->next = head;
    head = ptr;
  }
  else if(ptr->priority <= tail->priority)
  {
    tail->next = ptr;
    tail = ptr;
  }
  else
  {
    Node* bp;
    Node* rp = head;
    while(ptr->priority <= rp->priority)
    {
      bp = rp;
      rp = rp->next;
    }
    ptr->next = bp->next;
    bp->next = ptr;
  }
  count++;
  ptr = NULL;
}

Node* CPrioQueue::Remove()
{
  Node* ptr = head;
  if(head)
  {
    head = head->next;
    ptr->next = NULL;
  }
  else
  {
    tail = NULL; // Why need to do this?
  }
  if(count) count--; // Mistake correction?
  return ptr;
}

int main()
{
  Node* ptr1 = new Node(1, 1);
  Node* ptr2 = new Node(2, 2);
  Node* ptr3 = new Node(3, 3);
  Node* ptr4 = new Node(4, 4);
  Node* ptr5 = new Node(5, 5);

  CPrioQueue Q1;
  Q1.Add(ptr1);
  Q1.Add(ptr2);
  Q1.Add(ptr3);
  Q1.Add(ptr4);

  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;

  Q1.Add(ptr5);

  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;
  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;
  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;
  cout<<(Q1.Remove()->data);
  cout<<" "<<Q1.count<<endl;

  }
