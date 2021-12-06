// C++ program to print path between any
// two nodes in a Binary Tree
#include <bits/stdc++.h>
using namespace std;

// structure of a node of binary tree
struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

/* Helper function that allocates a new node with the
given val and NULL left and right pointers. */
struct TreeNode *getNode(int val)
{
    struct TreeNode *newNode = new TreeNode;
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if there is a path from root
// to the given node. It also populates
// 'arr' with the given path
bool getPath(TreeNode *root, vector<pair<char, int>> &arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // if it is the required node
    // return true
    if (root->val == x)
        return true;

    if (getPath(root->left, arr, x))
    {
        arr.push_back(make_pair('L', root->val));
        return true;
    }
    arr.pop_back();
    if (getPath(root->right, arr, x))
    {
        arr.push_back(make_pair('R', root->val));
        return true;
    }
    arr.pop_back();
    return false;
}

// Function to print the path between
// any two nodes in a binary tree
string printPathBetweenNodes(TreeNode *root, int n1, int n2)
{
    // vector to store the path of
    // first node n1 from root
    vector<pair<char, int>> path1;

    // vector to store the path of
    // second node n2 from root
    vector<pair<char, int>> path2;

    getPath(root, path1, n1);
    getPath(root, path2, n2);

    int intersection = -1;

    // Get intersection point
    int i = 0, j = 0;
    while (i != path1.size() || j != path2.size())
    {

        // Keep moving forward until no intersection
        // is found
        if (i == j && path1[i].second == path2[j].second)
        {
            i++;
            j++;
        }
        else
        {
            intersection = j - 1;
            break;
        }
    }

    string ans;
    // Print the required path
    for (int i = path1.size() - 1; i > intersection; i--)
        ans += "U";

    for (int i = intersection; i < path2.size(); i++)
        ans += path2[i].first;
    return ans;
}

// Driver program
int main()
{
    // binary tree formation
    struct TreeNode *root = getNode(0);
    root->left = getNode(1);
    root->left->left = getNode(3);
    root->left->left->left = getNode(7);
    root->left->right = getNode(4);
    root->left->right->left = getNode(8);
    root->left->right->right = getNode(9);
    root->right = getNode(2);
    root->right->left = getNode(5);
    root->right->right = getNode(6);

    int node1 = 7;
    int node2 = 4;
    printPathBetweenNodes(root, node1, node2);

    return 0;
}
