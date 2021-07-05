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
NODE *Separate(LIST& L)
{
    NODE* P = L.pHead;
    L.pHead = L.pHead->pNext;
    if (L.pHead == NULL)
        return P;
    P->pNext = NULL;
    return P;
}
void Partition(LIST& L, LIST& L1,NODE *&pivot, LIST& L2)
{
    pivot = Separate(L);
    NODE* P = L.pHead;
    while (L.pHead!=NULL)
    {
        NODE* T = Separate(L);
        if (T->info <= pivot->info)
            AddTail(L1, T);
        else
            AddTail(L2, T);
    }
}
void PrintList(LIST L)
{
    NODE* P = L.pHead;
    if (L.pHead == NULL)
        cout << "Empty List.";
    while (P)
    {
        cout << P->info << " ";
        P = P->pNext;
    }
    cout << "\n";
}

int main() 
{
	LIST L, L1, L2;
	NODE* pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateList(L);

	if (L.pHead == NULL) {
		cout << "Empty List.";
		return 0;
	}

	Partition(L, L1, pivot, L2);

	cout << pivot->info << endl;
	PrintList(L1);
	PrintList(L2);
	PrintList(L);

	return 0;
}
