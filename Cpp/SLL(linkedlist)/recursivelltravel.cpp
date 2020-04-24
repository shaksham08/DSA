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

void display(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << (head->data) << endl;
    display(head->next);
}

int main(int argc, char const *argv[])
{

    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    Node *temp2 = new Node(40);
    head->next = temp;
    temp->next = temp1;
    temp1->next = temp2;

    display(head);
    cout << "THis is a program to traverse through the singly liked list";
    return 0;
}
