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

Node *reverse(Node *head, Node *prev)
{
    if (head == NULL)
    {
        return prev;
    }
    Node *temp = head->next;
    head->next = prev;
    return reverse(temp, head);
}
void nthnode(Node *head, int x)
{
    if (head == NULL)
    {
        return;
    }
    Node *first = head;
    for (int i = 0; i < x; i++)
    {
        if (first == NULL)
        {
            return;
        }
        first = first->next;
    }
    Node *second = head;
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout << second->data << endl;
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
    cout << "Reversed" << endl;
    head = reverse(head, NULL);
    display(head);

    return 0;
}
