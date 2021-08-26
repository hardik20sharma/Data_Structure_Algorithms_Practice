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

void vertical_traversal_util(Node *root, int horizontal_distance, map<int, vector<int>> &m)
{
    if(root == NULL)
        return;
    
    m[horizontal_distance].push_back(root->data);

    vertical_traversal_util(root->left, horizontal_distance - 1, m);
    vertical_traversal_util(root->right, horizontal_distance + 1, m);
}

void bottom_view(Node *root)
{
    if(root == NULL)
        return;
    
    map<int, vector<int>> m;

    vertical_traversal_util(root, 0, m);

    for(pair<int, vector<int>> map_elements : m)
        cout << map_elements.second[map_elements.second.size() - 1] << " ";
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

    bottom_view(root);
}

/*
        Tree looks like

                0
        1               2
    3       4       5       6
*/
