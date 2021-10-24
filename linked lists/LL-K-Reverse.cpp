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

void insert(node *&head, int data, node *&tail)
{
    if (head == NULL)
    {
        head = new node(data);
        tail = head;
        return;
    }

    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

node *reverse(node *head, int k)
{
    node *curr = head, *prev = NULL, *nxt = NULL;
    int count = 0;
    while (curr != NULL and count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count ++;
    }
    if (nxt != NULL)
    {
        head->next = reverse(nxt, k);
    }
    return prev;
}

void print(node *head) // pass by value so that original head can be retained
{
    while (head != NULL)
    {
        cout << head->data << " => ";
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n, num, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        insert(head, num, tail);
    }
    print(head);
    cout << endl;
    print(reverse(head,k));
    return 0;
}