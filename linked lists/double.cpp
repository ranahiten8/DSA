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

void insertAThead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void print(node *head) // pass by value so that original head can be retained
{
    while (head != NULL)
    {
        cout << head->data << " => ";
        head = head->next;
    }
}

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}

istream &operator>>(istream &is, node *&head)
{
    head = NULL;
    int n, data;
    cout << "Enter total numbers:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insertAThead(head, data);
    }
    return is;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    return 0;
}