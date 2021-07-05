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
NODE* Search(LIST L, int k)
{
	int dem = 0;
	NODE* P = L.pHead;
	NODE* Q = new NODE;
	while (P != NULL)
	{
		dem++;
		Q = P;
		P = P->pNext;
		if (dem == k)
			return Q;
	}
	return NULL;
}
void add_after_k_th (LIST& L, int Y, int k)
{
	NODE* P = new NODE;
	P->info = Y;
	P->pNext = NULL;
	NODE* T = Search(L, k);
	if (T == NULL)
		return;
	else if (T == L.pTail)
	{
		L.pTail->pNext = P;
		L.pTail = P;
	}
	else
	{
		P->pNext = T->pNext;
		T->pNext = P;
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
	else
	{
		NODE* T = new NODE;
		do
		{
			cout << P->info << " ";
			T = P;
			P = P->pNext;
		} while (T->pNext != NULL);
	}
}

int main() {
	LIST L;
	int k, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> k >> Y;
	add_after_k_th(L, Y, k);

	PrintList(L);

	return 0;
}
