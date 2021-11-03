#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void vertical(node *root, int d, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }

    m[d].push_back(root->data);
    vertical(root->left, d - 1, m);
    vertical(root->right, d + 1, m);
}

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->right->right->right = new node(9);

    root->left->right->right = new node(8);

    map<int, vector<int>> m;
    vertical(root, 0, m);

    for (auto x : m)
    {
        cout << x.first << " : ";
        for (auto p : x.second)
        {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}