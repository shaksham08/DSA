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

int maximum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    std::max(1, 2);
    return std::max(maximum(root->left), std::max(maximum(root->right), root->data));
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(25);
    root->left = new Node(1);
    root->right = new Node(2);
    preorder(root);
    std::cout << std::endl
              << maximum(root) << std::endl;
    std::cin.get();
    delete root;
    return 0;
}
