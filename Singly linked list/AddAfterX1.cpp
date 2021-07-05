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
void AddTail(LIST& L, int x)
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
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void CreateList(LIST& L)
{
	int  x;
	cin >> x;
	while (x != -1)
	{
		AddTail(L, x);
		cin >> x;
	}
}
NODE* Search(LIST L, int X)
{
	NODE* P = L.pHead;
	while (P != NULL && P->info != X)
		P = P->pNext;
	return P;
}
void add_afterX_1(LIST& L, int Y, int X)
{
	NODE* P = new NODE;
	P->info = Y;
	P->pNext = NULL;
	NODE* T = Search(L, X);
	if (T == NULL)
		return;
	else
	{
		P->pNext = T->pNext;
		T->pNext = P;
	}
	
}
void PrintList(NODE* L)
{
	if (L == NULL)
	{
		cout << "Empty List.";
		return;
	}
	else
	{
		NODE* T = new NODE;
			do
			{
				cout << L->info << " ";
				T = L;
				L = L->pNext;
			} while (T->pNext != NULL);
	}
}
int main() {
	LIST L;
	int X, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> X >> Y;
	add_afterX_1(L, Y, X);

	PrintList(L.pHead);

	return 0;
}


