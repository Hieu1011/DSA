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
void CreateEmptyList (LIST &L)
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
void PrintList_Odd(NODE *L)
{
    NODE* p;
    int x = 0;
    if (L == NULL)
    {
        cout << "Empty List.";
        return;
    }
    else
    {
        p = L;
        while (p)
        {
            if (p->info % 2 != 0)
            {
                cout << p->info << " ";
                x++;
            }
            p = p->pNext;
        }
    }
    if (x == 0)
        cout << "Không có số lẻ trong mảng.";
}
int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Odd(L.pHead);

    return 0;
}
