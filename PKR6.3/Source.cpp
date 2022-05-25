#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
}

void print(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << " ";
        first = first->next;
    }
}

void Change(Elem* L)
{
    Elem* tmp = new Elem;

    while (L->next != NULL)
    {
        tmp->info = L->info;
        L->info = L->next->info;
        L->next->info = tmp->info;
        if (L->next->next == NULL)
        {
            L = L->next;
        }
        else
        {
            L = L->next->next;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;


    int N, value;

    cout << "¬вед≥ть к≥льк≥сть елемент≥в: "; cin >> N;

    for (int i = 0; i < N; i++)
    {
        cout << "¬вед≥ть значенн€ " << i + 1 << " елементу: "; cin >> value;
        enqueue(first, last, value);
    }
    cout << endl;

    cout << "—писок: "; print(first); cout << endl << endl;

    Change(first);
    
    cout << "«м≥нений список: "; print(first); cout << endl << endl;

    dequeue(first, last);

    system("pause");
    return 0;
}