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

void search(Node *head, int num)
{
    int count = 0;
    while (head != NULL)
    {

        if (head->data == num)
        {
            cout << "The position is : " << count + 1;
        }
        head = head->next;
        count++;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp;
    temp->next = temp2;
    search(head, 20);

    return 0;
}
