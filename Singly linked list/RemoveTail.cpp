#include<iostream>
using namespace std;
struct NODE
{
    int info;
    NODE* pNext;
};
struct LIST
{
    NODE* pHead, * pTail;
};
void CreateEmptyList(LIST& L)
{
    L.pHead = L.pTail = NULL;
}
void Addtail(LIST& L, int n)
{
    NODE* P = new NODE;
    P->info = n;
    P->pNext = NULL;
    if (L.pHead == NULL)
    {
        L.pHead = P;
        L.pTail = L.pHead;//
    }
    else
    {
        L.pTail->pNext = P;
        L.pTail = P;
    }
}
void CreateList(LIST& L)
{
    int n;
    cin >> n;
    while (n != -1)
    {
        Addtail(L, n);
        cin >> n;
    }
}
void RemoveTail(LIST& L)
{
    NODE* P = new NODE;
    if (L.pHead == NULL)
        return;
    else if (L.pTail == L.pHead)
    {
        L.pHead = NULL;
        return;
    }
    for (NODE* T = L.pHead; T != NULL; T = T->pNext)
    {

        if (T->pNext == L.pTail)
        {
            T->pNext = NULL;
            L.pTail = T;
            return;
        }
    }
}
void PrintList(LIST L)
{
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    NODE* P = L.pHead;
    NODE* T = new NODE;
    do
    {
        cout << P->info << " ";
        T = P;
        P = P->pNext;
    } while (T->pNext != NULL);
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    RemoveTail(L);
    PrintList(L);

    return 0;
}
