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

int number(node *head, int posi)
{
    node *fast = head;
    node *slow = head;
    for (int i = 1; i < posi && fast->next != NULL; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
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
    int num, posi;
    while (1)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        insert(head, num, tail);
    }
    cin >> posi;
    cout << number(head, posi);
}