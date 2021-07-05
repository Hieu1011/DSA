#include <iostream>
#include <math.h>
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
void AddHead(int x,LIST& L)
{
    NODE* P = new NODE;
    P->info = x;
    P->pNext = NULL;
    if (L.pHead == NULL)
    {
        L.pHead = P;
        L.pTail = L.pHead;
    }
    else
    {
        P->pNext = L.pHead;
        L.pHead = P;
    }
}
int dem(int x)
{
    int n = 0;
    while (x > 0)
    {
        x /= 10;
        ++n;
    }
    return n;
}
bool Arm(int x)
{
    int f = x, t;
    double s = 0;
    if (x <= 0)
        return false;
    int n = dem(x);
    while (f > 0)
    {
        t = f % 10;
        s += pow(double(t), n);
        f /= 10;  
    }
    if (s == double(x))
        return true;
    return false;
}
void CreateList(LIST &L)
{
    int x;
    cin >> x;
    while (x != -1)
    {
        AddHead(x, L);
        cin >> x;
    }
}
void PrintList_Armstrong(LIST L)
{
    int dem = 0;
    NODE* p = L.pHead;
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    else
    {
        do
        {
            if (Arm(p->info)==true)
            {
                cout << p->info << " ";
                dem++;
            }
            p = p->pNext;
        } while (p != NULL);
        if (dem == 0)
            cout << "Không có số armstrong trong mảng.";
    }
}
int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}
