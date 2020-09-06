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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return std::max(height(root->left), height(root->right)) + 1;
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    preorder(root);
    std::cout << "\n"
              << height(root) << std::endl;
    std::cin.get();
    delete root;
    return 0;
}
