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
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);

        postorder(root->right);
        std::cout << root->data << " ";
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    postorder(root);
    std::cin.get();
    delete root;
    return 0;
}
