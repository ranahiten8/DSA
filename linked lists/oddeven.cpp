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

bool check(int num)
{
    cout << "number check " << num << endl;
    if (num % 2 == 0)
    {
        return true;
    }
    return false;
}

void oddeven(node *&head, node *&tail, int n)
{
    node *curr = head;
    node *prev = NULL;
    node *nex;
    bool flag;
    while (n--)
    {
        flag = check(curr->data);
        if (curr == head)
        {
            if (flag)
            {
                cout << "head condition" << endl;
                head = head->next;
                curr->next = NULL;
                tail->next = curr;
                tail = tail->next;
                curr = head;
            }
            prev == curr;
            curr = curr->next;
            cout << "curr data " << curr->data << endl;
        }
        else
        {
            if (flag)
            {
                cout << "normal" << endl;
                prev->next = curr->next;
                nex=curr->next;
                curr->next = NULL;
                tail->next = curr;
                tail = tail->next;
            }
            curr = nex;
            cout << "curr data else " << curr->data << endl;
        }
    }
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
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
    oddeven(head, tail, n);
    print(head);
}