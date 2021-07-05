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
void RemoveHead(LIST& L)
{
	if (L.pHead != NULL)
	{
		L.pHead = L.pHead->pNext;
		if (L.pHead == NULL)
			L.pTail = NULL;
	}
}
void RemoveX(LIST& L, int x)
{
	NODE* P = L.pHead;
	NODE* Q = L.pHead;
	if (L.pHead == NULL)
		return;
	if (L.pHead->info == x)
	{
		RemoveHead(L);
		return;
	}
	while (P != NULL)
	{
		if (P->info == x)
		{
			while (Q != P)
			{
				if (Q->pNext == P)
				{
					if (P == L.pTail)
					{
						Q->pNext = NULL;
						L.pTail = Q;
						return;
					}
					else
					{
						Q->pNext = P->pNext;
						return;
					}
				}
				Q = Q->pNext;
			}
		}
		P = P->pNext;
	}
	return;
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
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	RemoveX(L, X);
	PrintList(L);

	return 0;
}
