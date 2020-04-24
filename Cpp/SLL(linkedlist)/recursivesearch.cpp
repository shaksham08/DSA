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

int search(Node *head, int n)
{
    if (head == NULL)
        return -1;
    if (head->data == n)
    {
        return 1;
    }
    else
    {
        int res = search(head->next, n);
        if (res == -1)
            return -1;
        else
            return res + 1;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp;
    temp->next = temp2;
    int pos = search(head, 30);
    cout << pos;
    return 0;
}
