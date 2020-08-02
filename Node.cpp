struct Node{
int data;
Node* next;
int priority;

Node();
Node(int data, int priority);
};

Node::Node():data(0), next(NULL), priority(0)
{

}

Node::Node(int data, int priority):data(data), next(NULL), priority(priority)
{

}
