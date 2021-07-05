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
void CreateEmptyList(LIST &L)
{
	L.pHead = L.pTail = NULL;
}
void Addhead(LIST &L, int x)
{
	NODE* p = new NODE;
	p->info = x;
	p->pNext = NULL;
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}
void CreateList(LIST& L)
{
	int  x;
	cin >> x;
	while (x!= -1)
	{
		Addhead(L, x);
		cin >> x;
	}
}

void PrintList( LIST L)
{
	if (L.pHead == NULL)
	{
		cout << "Empty List.";
		return;
	}
	NODE* P = L.pHead;
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
	PrintList(L);
	return 0;
}
