#include <iostream>
using namespace std;

class node
{
public:
    int data; //data member hota h ye
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertathead(node *&head, int data)
{
    node *n = new node(data);
    node *temp = head;

    n->next = head;
    if (temp != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n;
    }
    head = n;
}

node *getnode(node *head, int d)
{
    node *temp = head;
    //for all nodes except last node
    while (temp->next != head)
    {
        if (temp->data == d)
        {
            return temp;
        }
        temp = temp->next;
    }

    //for last node which is not checked
    if (temp->data == d)
    {
        return temp;
    }
    return NULL;
}

void deletenode(node *&head, int data)
{
    node *del = getnode(head, data);
    if (del == NULL)
    {
        return;
    }
    //otherwise
    if (head == del)
    {
        head = head->next; // head update krna pdega agar del==head hai to
    }

    node *temp = head;
    //stop one step behind the node to be deleted
    while (temp->next != del)
    {
        temp = temp->next;
    }
    temp->next = del->next; //node ke links update krdo
    delete del;             //delete krdo
}

void print(node *head)
{
    node *temp = head;
    //for all nodes
    while (temp->next != head)
    {
        cout << temp->data << " => ";
        temp = temp->next;
    }

    //for last node which is not printed
    cout << temp->data << " => ";
}

int main()
{
    node *head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    insertathead(head, 3);
    insertathead(head, 4);
    print(head);
    cout << endl;

    node *posi = getnode(head, 3);
    cout << posi->data << endl;

    deletenode(head, 3);
    print(head);

    return 0;
}