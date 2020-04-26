#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertatstart(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    return temp;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << (head->data) << endl;
        head = head->next;
    }
}
int main()

{
    Node *head = NULL;
    head = insertatstart(head, 10);
    head = insertatstart(head, 20);
    head = insertatstart(head, 30);
    //! It should print 30 20 10
    display(head);

    return 0;
}