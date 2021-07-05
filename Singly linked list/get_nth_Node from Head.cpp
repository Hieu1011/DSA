#include <iostream>
#include <string.h>
using namespace std;
struct NODE {
	int info;
	NODE* pNext;
};
struct LIST {
	NODE* pHead;
	NODE* pTail;
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
int get_nth_node_from_head(NODE* L, int k)
{
	if (k <= 0)
		return -1;
	int dem = 1;
	for (NODE* P = L; P != NULL; P = P->pNext)
	{
		if (dem == k)
			return P->info;
		dem++;
	}
	return -1;
}
int main() {
	LIST L;
	int k;
	CreateEmptyList(L);
	CreateList(L);

	cin >> k;
	cout << get_nth_node_from_head(L.pHead, k);

	return 0;
}
