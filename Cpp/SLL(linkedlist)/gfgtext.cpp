

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
void insertatpos(Node *head, int pos, int data)
{
    if (head == NULL)
    {
        return;
    }
    int count = 1;
    Node *curr = head;
    while (count != pos)
    {
        if (curr == NULL || curr->next == NULL)
        {

            return;
        }

        count++;
        curr = curr->next;
    }

    Node *newnode = new Node(data);
    Node *temp = curr->next;
    curr->next = newnode;
    newnode->next = temp;
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
    cout << "Insertig" << endl;
    // insertatpos(head, 2, 70);
    // insertatpos(head, 4, 70);
    insertatpos(head, 5, 100);
    cout << "Insertig" << endl;
    display(head);
    return 0;
}
