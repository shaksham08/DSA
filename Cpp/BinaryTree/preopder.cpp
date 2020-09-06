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

//!postoder Traversal Code
void preorder(Node *root)
{
    if (root != NULL)
    {
        std::cout << root->data << " ";
        preorder(root->left);

        preorder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    preorder(root);
    std::cin.get();
    delete root;
    return 0;
}
