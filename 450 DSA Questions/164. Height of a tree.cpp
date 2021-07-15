#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int tree_height(Node *root)
{
    if(root == NULL)
        return 0;

    return 1 + max(tree_height(root->left), tree_height(root->right));
}

int main()
{
    Node *root = new Node(0);

    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(6);

    cout << tree_height(root) << "\n";
}