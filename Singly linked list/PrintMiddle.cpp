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
double dem(LIST L)
{
	double dem = 0;
	NODE* P = L.pHead;
	while (P != NULL)
	{
		dem++;
		P = P->pNext;
	}
	return dem / 2;
}
void Print_Middle(LIST L)
{
	NODE* P = L.pHead;
	double s = dem(L);
	int k = 1;
	if (L.pHead == NULL)
	{
		cout << "Empty List.";
		return;
	}
	else if (L.pHead == L.pTail)
	{
		cout << L.pHead->info;
		return;
	}
	else
	{
		for (; k <= s+0.5; k++)
		{
			if (k == s)
			{
				cout << P->info;
				return;
			}
			if (k == s + 0.5)
			{
				cout << P->info;
				return;
			}
			P = P->pNext;
		}
	}
}
int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    Print_Middle(L);

    return 0;
}
