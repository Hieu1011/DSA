#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};
NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST& L) {
    L.pHead = L.pTail = NULL;
}

void AddTail(LIST& L, NODE* p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void CreateList(LIST& L) {
    int x;
    cin >> x;
    while (x != -1) {
        AddTail(L, CreateNode(x));
        cin >> x;
    }
}

void Join(LIST& L, LIST L1, NODE* pivot, LIST L2)
{
    NODE* p = L1.pHead;
    if (p != NULL)
        while (p)
        {
            AddTail(L, p);
            p = p->pNext;
        }
    if (pivot != NULL)
        AddTail(L, pivot);
    p = L2.pHead;
    if (p != NULL)
        while (p)
        {
            AddTail(L, p);
            p = p->pNext;
        }
}
void PrintList(LIST L)
{
    NODE* p = L.pHead;
    while (p)
    {
        cout << p->info << ' ';
        p = p->pNext;
    }
}
int main() {
	LIST L, L1, L2;

	int x;
	NODE* pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList(L1);
	cin >> x;
	pivot = CreateNode(x);
	CreateList(L2);


	Join(L, L1, pivot, L2);
	PrintList(L);

	return 0;
}
