#include <iostream>

struct Node
{
    int data;
    Node *right, *left;
    Node(int x)
    {
        data = x;
        right = left = NULL;
    }
};

//!inoder Traversal Code
void inoder(Node *root)
{
    if (root != NULL)
    {
        inoder(root->left);
        std::cout << root->data << " ";
        inoder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    inoder(root);
    std::cin.get();
    delete root;
    return 0;
}
