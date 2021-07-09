#include<bits/stdc++.h>
using namespace std;

struct tree_node
{
    int data;
    tree_node *left, *right;

    tree_node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void level_order(tree_node *root)
{
    if(root == NULL)
        return;

    queue<tree_node *> q;

    q.push(root);

    while(!q.empty())
    {
        cout << q.front()->data << " ";

        if(q.front()->left != NULL)
            q.push(q.front()->left);
        
        if(q.front()->right != NULL)
            q.push(q.front()->right);
        
        q.pop();
    }
}

int main()
{
    tree_node *root = new tree_node(0);

    root->left = new tree_node(1);
    root->right = new tree_node(2);
    root->left->left = new tree_node(3);
    root->right->right = new tree_node(4);

    level_order(root);
}