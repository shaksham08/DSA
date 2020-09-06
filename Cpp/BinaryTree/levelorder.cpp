#include <iostream>
#include <queue>
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

//!levelOrder
void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    std::queue<Node *> q;
    q.push(root);
    while (q.empty() != true)
    {
        Node *curr = q.front();
        q.pop();
        std::cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    levelorder(root);
    std::cin.get();
    delete root;
    return 0;
}
