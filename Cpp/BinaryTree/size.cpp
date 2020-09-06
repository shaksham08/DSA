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

int size(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    preorder(root);
    std::cout << std::endl;
    std::cout << "The size if : " << size(root) << std::endl;
    std::cin.get();
    delete root;
    return 0;
}
