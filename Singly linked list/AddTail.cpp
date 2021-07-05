#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE* pNext;
};
struct LIST
{
    NODE* pHead, *pTail;
};
void CreateEmptyList(LIST &L)
{
    L.pHead = L.pTail = NULL;
}
void Addtail(LIST &L, int n)
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
void CreateList(LIST &L)
{
    int n;
    cin >> n;
    while (n != -1)
    {
        Addtail(L, n);
        cin >> n;
    }
}
void PrintList(NODE* L)
{
    if (L == NULL)
    {
        cout << "Empty List.";
        return;
    }
    NODE* P = L;
    NODE* T;
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
    PrintList(L.pHead);

    return 0;
}