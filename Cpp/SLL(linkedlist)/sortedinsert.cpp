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
Node *insertsorted(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }
    if (head->data > x)
    {
        temp->next = NULL;
        return temp;
    }
    Node *curr = head;
    while (curr->next->data < x && curr->next != NULL)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

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

int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    head = insertatend(head, 20);
    head = insertatend(head, 30);
    head = insertatend(head, 40);
    display(head);
    cout << "Inserting sorted" << endl;
    head = insertsorted(head, 15);
    head = insertsorted(head, 21);
    display(head);
    return 0;
}
