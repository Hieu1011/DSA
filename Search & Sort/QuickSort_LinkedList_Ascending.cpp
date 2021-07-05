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
	//if (p == NULL)
	//		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST& L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail = p;
	}
}

void CreateEmptyList(LIST& L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST& L) {
	NODE* p;
	int x, n;
	cin >> n; // Số lượng phần tử của danh sách
	while (n-- > 0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}

bool is_ascending(NODE* head)
{
	if (head == NULL || head->pNext == NULL)
		return 0;
	return 1;
}
NODE* Separate(LIST& L)
{
	NODE* P = L.pHead;
	L.pHead = L.pHead->pNext;
	if (L.pHead == NULL)
		return P;
	P->pNext = NULL;
	return P;
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
void Partition(LIST& L, LIST& L1, NODE*& pivot, LIST& L2)
{
	pivot = Separate(L);
	NODE* P = L.pHead;
	while (L.pHead != NULL)
	{
		NODE* T = Separate(L);
		if (T->info <= pivot->info)
			AddTail(L1, T);
		else
			AddTail(L2, T);
	}
}
void quicksort_ascending(LIST& L)
{
	NODE* pivot;
	LIST L1, L2;
	if (!is_ascending(L.pHead))
		return;
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	Partition(L, L1, pivot, L2);
	quicksort_ascending(L1);
	quicksort_ascending(L2);
	Join(L, L1, pivot, L2);
}

int length(NODE* p) {
	int i = 0;
	while (p) {
		i++;
		p = p->pNext;
	}
	return i;
}

void PrintList(NODE* p) {
	if (p == NULL)
		cout << "Empty List.";
	else {
		// cout << boolalpha << is_ascending(p) << endl;
		cout << length(p) << endl;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}
int main() {
	LIST L;
	CreateEmptyList(L);

	CreateList(L);
	quicksort_ascending(L);
	PrintList(L.pHead);

	return 0;
}
