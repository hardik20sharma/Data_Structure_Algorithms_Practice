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

void in_order_recursion(Node *root)
{
    if(root == NULL)
        return;

    in_order_recursion(root->left);
    cout << root->data << " ";
    in_order_recursion(root->right);
}

void in_order_iterative(Node *root)
{
    stack<Node* > s;

    while(root != NULL || !s.empty())
    {
        while(root != NULL)
        {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();

        cout << root->data << " ";

        root = root->right;
    }
}

void in_order_iterative_easy(Node *root)
{
    stack< pair< Node*, int > > s;

    s.push( {root, 0} );

    while(!s.empty())
    {
        Node *curr_node = s.top().first;
        int curr_state = s.top().second;

        s.pop();

        if(curr_node == NULL || curr_state == 3)
            continue;

        s.push( {curr_node, curr_state + 1} );

        if(curr_state == 0)
            s.push( {curr_node->left, 0} );
        
        else if(curr_state == 1)
            cout << curr_node->data << " ";
        
        else
            s.push( {curr_node->right, 0} );
    }
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

    in_order_iterative(root);

    cout << endl << endl;

    in_order_recursion(root);
    
    cout << endl << endl;

    in_order_iterative_easy(root);
}