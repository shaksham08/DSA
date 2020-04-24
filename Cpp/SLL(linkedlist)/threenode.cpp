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
int main()

{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    Node *temp2 = new Node(40);
    head->next = temp;
    temp->next = temp1;
    temp1->next = temp2;

    cout << "This is the basic Linked list containing three elements";
    cout << "\nThis is working fine withour error";
    return 0;
}