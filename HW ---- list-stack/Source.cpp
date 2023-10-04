#include <iostream>
using namespace std;

struct Elem
{
    int data;
    Elem* next, * prev;
};

class StackList
{
    Elem* Head, * Tail;
    int Count;

public:

    StackList();
    ~StackList();
    int GetCount();
    void DelAll();
    void Pop();
    void Push(int n);
    void Print();
};

StackList::StackList()
{
    Head = Tail = NULL;
    Count = 0;
}


StackList::~StackList()
{
    DelAll();
}

void StackList::Push(int n)
{
    Elem* temp = new Elem;
    temp->next = 0;
    temp->data = n;
    temp->prev = Tail;

    if (Tail != 0)
        Tail->next = temp;

    if (Count == 0)
        Head = Tail = temp;
    else
        Tail = temp;

    Count++;
}

void StackList::Pop()
{
    int pos = Count;
    int i = 1;
    Elem* Del = Head;
    while (i < pos)
    {
        Del = Del->next;
        i++;
    }
    Elem* PrevDel = Del->prev;
    Elem* AfterDel = Del->next;
        
    if (PrevDel != 0 && Count != 1)
        PrevDel->next = AfterDel;
    if (pos == Count)
        Tail = PrevDel;
        
    delete Del;
    Count--;
}

void StackList::Print()
{
    if (Count != 0)
    {
        Elem* temp = Head;
        cout << "( ";
        while (temp->next != NULL)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}

void StackList::DelAll()
{
    while (Count != 0)
        Pop();
}

int StackList::GetCount()
{
    return Count;
}

int main()
{
    StackList L;

    L.Push(1);
    L.Push(2);
    L.Push(3);
    L.Push(4);
    L.Push(5);

    // Распечатка списка
    cout << "List L:\n";
    L.Print();

    cout << endl;

    L.Push(6);
    cout << "List L:\n";
    L.Print();
    L.Pop();
    L.Print();
    L.Pop();
    L.Print();
}

