#include <iostream>
using namespace std;

class node
{
public:
    int data; //data member hota h ye
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
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
    temp->prev = tail;
    tail = temp;
}

bool check(node *head, node *tail, int mid)
{
    int cnt = 0;
    while (cnt < mid)
    {
        if (head->data == tail->data)
        {
            head = head->next;
            tail = tail->prev;
        }
        else
        {
            return false;
        }
        cnt++;
    }
    return true;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        insert(head, num, tail);
    }
    int mid = n / 2;
    bool ans = check(head, tail, mid);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}