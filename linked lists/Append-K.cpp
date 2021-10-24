#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void getLinkedList(node *&head, int n)
{
    int x;
    cin >> x; //first input;
    head = new node(x);
    node *current = head;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        node *n = new node(x);
        current->next = n;
        current = n;
    }
    current->next = NULL;
}

node *appendK(node *head, int k)
{
    node *oldHead = head;
    node *fast = head;
    node *slow = head;
    for (int i = 0; i < k && fast->next != NULL; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    node *newHead = slow->next;
    slow->next = NULL;
    fast->next = oldHead;
    return newHead;
}

int main()
{
    node *head = NULL;
    int n;
    cin >> n;
    getLinkedList(head, n);
    int k;
    cin >> k;
    k = k % n;
    if (k == 0)
    {
        print(head);
    }
    else
    {
        head = appendK(head, k);
        print(head);
    }
    return 0;
}