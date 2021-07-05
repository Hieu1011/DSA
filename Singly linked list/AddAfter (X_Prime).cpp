#include <iostream>
using namespace std;
#include <math.h>
struct NODE
{
	int info;
	NODE* pNext;
};
struct LIST
{
	NODE* pHead, * pTail;
};
bool snt(int x)
{
	if (x < 2)
		return 0;
	else
	{
		for (int i = 2; i <= sqrt(x); i++)
			if (x % i == 0)
				return 0;
	}
	return 1;
}
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
void add(LIST& L, NODE* T, int Y)
{
	NODE* P = new NODE;
	P->info = Y;
	P->pNext = NULL;
	if (T != NULL) {
		P->pNext = T->pNext;
		T->pNext = P;
		if (L.pTail == T)
			L.pTail = P;
	}
}
void add_after_all_prime(LIST& L, int Y)
{
	NODE* T = L.pHead;
	if (T == NULL)
		return;
	else
	{
		do
		{
			if (snt(T->info))
			{
				add(L, T, Y);
				T = T->pNext->pNext;
			}
			else
				T = T->pNext;
		} while (T != NULL);
	}
}
void PrintList(LIST L)
{
	NODE* P = L.pHead;
	if (P == NULL)
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
	int Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_all_prime(L, Y);

	PrintList(L);

	return 0;
}

