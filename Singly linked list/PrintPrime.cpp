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
void PrintList_Prime(LIST L)
{
	int dem = 0;
	if (L.pHead == NULL)
	{
		cout << "Empty List.";
		return;
	}
	NODE* P = L.pHead;
	NODE* T = new NODE;
	do
	{
		if (snt(P->info) == 1)
		{
			cout << P->info << " ";
			dem++;
		}
		T = P;
		P = P->pNext;
	} while (T->pNext != NULL);
	if (dem == 0)
		cout << "Không có số nguyên tố trong mảng.";
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Prime(L);

    return 0;
}
