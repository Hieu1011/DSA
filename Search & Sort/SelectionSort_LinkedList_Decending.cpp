
#include <iostream>
using namespace std;


struct NODE {
	int info;
	NODE* pNext;
};

struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
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
	cin >> n; 
	while (n-- > 0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}

int length(NODE* p) {
	int i = 0;
	while (p) {
		i++;
		p = p->pNext;
	}
	return i;
}

bool is_ascending(NODE* head) {
	if (head == NULL) return 0;
	while (head->pNext != NULL) {
		if (head->info > head->pNext->info) return 0;
		head = head->pNext;
	}
	return 1;
}
void PrintList(NODE* p) {
	if (p == NULL)
		cout << "0";
	else {
		cout << length(p) << endl;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}
void hoanvi(int& a, int& b) {
	int temp = a; a = b; b = temp;
}
void selectionSort_decending(LIST& L) {
	NODE* P = L.pHead;
	while (P)
	{
		NODE* A = P;
		for (NODE* T = P->pNext; T != NULL; T = T->pNext)
		{
			if (A->info < T->info)
				A = T;
		}
		hoanvi(P->info, A->info);
		P = P->pNext;
	}
}
int main() {
	LIST L;
	CreateEmptyList(L);

	CreateList(L);
	selectionSort_decending(L);
	PrintList(L.pHead);

	return 0;
}



