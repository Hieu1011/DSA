#include <iostream>
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
        L.pTail = L.pHead;
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
void RemoveHead(LIST &L)
{
    NODE* p;
    if (L.pHead != NULL)
    {
        p = L.pHead;
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL)
            L.pTail = NULL;
        delete p;
    }
}
void PrintList(LIST L)
{
    NODE* P = L.pHead;
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    while (P != L.pTail)
    {
        cout << P->info << " ";
        P = P->pNext;
    }
    cout << P->info;
}
int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    RemoveHead(L);
    PrintList(L);

    return 0;
}
