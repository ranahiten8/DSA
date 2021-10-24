#include <iostream>
#include <queue>
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
        left = NULL;
        right = NULL;
    }
};

node *buildTree() //preorder build
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(node *root) //root, left, right
{
    if (root == NULL)
    {
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) //left,root,right
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root) //left,right,root
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void printKthLevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

int printATdistanceK(node *root, node *target, int k)
{
    //base case
    if (root == NULL)
    {
        return -1;
    }
    // reach the target node
    if (root == target)
    {
        printKthLevel(target, k);
        return 0;
    }
    //next step- ancestor node
    int DL = printATdistanceK(root->left, target, k);

    if (DL != -1)
    {
        //2 cases
        //ancestor itself or u need to go to right ancestor
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->right, k - 2 - DL);
        }
        return 1 + DL;
    }

    int DR = printATdistanceK(root->right, target, k);
    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->left, k - 2 - DR);
        }
        return 1 + DR;
    }
    //node not present in left or right
    return -1;
}

void printAllLevels(node *root) //not efficient bfs is efficient O(n^2)
{
    int H = height(root);

    for (int i = 1; i <= H; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    //return root node count(which is 1) + left subtree node count + right count
    return 1 + count(root->left) + count(root->right); 
}

void bfs(node *root) // O(n)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);   //push null so that we can print level wise

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;  // inserts a new line character when encounter null
            q.pop();
            if (!q.empty()) // to avoid infinite loop check if not empty
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << ",";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

void mirror(node *root)
{
    if (root == NULL)
    {
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
    return;
}

class Pair
{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root) // O(n) time
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

int replaceSum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    //Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}

class HBPair
{
public:
    int height;
    bool balance;
};

HBPair isHeightBalance(node *root) // bottom up approach post order O(n) time
{
    HBPair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }
    //Recurisve Case
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }
    return p;
}

node *buildTreeFromArray(int *a, int s, int e)
{
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Recursive Case
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid - 1);
    root->right = buildTreeFromArray(a, mid + 1, e);
    return root;
}

node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    //creating tree using inorder and preorder traversal given
    static int i = 0;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    int index = -1;
    for (int j = s; s <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index + 1, e);
    return root;
}

node *printrightview(node *root, int level, int &maxlevel)
{
    //to print right view of a given tree level wise
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        cout << root->data << " ";
        maxlevel = level;
    }

    //right
    //left
    printrightview(root->right, level + 1, maxlevel);
    printrightview(root->left, level + 1, maxlevel);
}

node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a or root->data == b)
    {
        return root;
    }

    //search in left and right subtrees
    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);
    if (leftans != NULL and rightans != NULL)
    {
        return root;
    }

    if (leftans != NULL)
    {
        return leftans;
    }
    //else
    return rightans;
}

//finding level of given node from the root node/any given node
int search(node *root, int key, int level)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data)
    {
        return level;
    }

    int left = search(root->left, key, level + 1);
    if (left != -1)
    {
        return left;
    }
    //else
    return search(root->right, key, level + 1);
}

//fn to find distance between 2 node
int findDistance(node *root, int a, int b)
{
    node *lca_node = lca(root, a, b);

    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);
    return l1 + l2;
}

int main()
{
    //node* root = buildTree();
    //cout<<count(root)<<endl;
    //printAllLevels(root);
    //Pair p = fastDiameter(root);
    //cout<<p.height<<endl;
    //cout<<p.diameter<<endl;

    // int a[] = {1, 2, 3, 4, 5, 6, 7};
    // int n = 7;
    // node *root = buildTreeFromArray(a, 0, n - 1);
    // bfs(root);

    // int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    // int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    // int n = sizeof(in) / sizeof(int);
    // node *root = createTreeFromTrav(in, pre, 0, n - 1);
    // bfs(root);

    // node*target=root->left->left;

    return 0;
}