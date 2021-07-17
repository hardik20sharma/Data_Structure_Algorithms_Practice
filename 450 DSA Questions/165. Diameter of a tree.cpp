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

int height_tree(Node *root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height_tree(root->left), height_tree(root->right));
}

int diameter_tree(Node *root)
{
    if(root == NULL)
        return 0;

    int curr_diameter = height_tree(root->left) + height_tree(root->right) + 1;
    int left_diameter = diameter_tree(root->left);
    int right_diameter = diameter_tree(root->right);

    return max(curr_diameter, max(left_diameter, right_diameter));
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

    cout << diameter_tree(root);
}