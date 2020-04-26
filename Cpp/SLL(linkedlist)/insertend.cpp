#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    //consructor
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertatend(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;

    return head;
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
    head = insertatend(head, 10);
    head = insertatend(head, 20);
    head = insertatend(head, 30);
    //! It should print 10 20 30
    display(head);

    return 0;
}