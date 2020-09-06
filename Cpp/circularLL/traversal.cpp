#include <iostream>
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
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    Node *temp = head->next;
    head->next = newnode;
    int databackup = head->data;
    head->data = data;
    newnode->next = temp;
    temp->data = databackup;
    return head;
}

void display(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    Node *curr = head->next;
    while (curr != head)
    {
        cout << curr->data << " ";
    }
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    head->next = head;
    head = insertatstart(head, 15);
    head = insertatstart(head, 11);
    head = insertatstart(head, 9);
    display(head);
    return 0;
}
