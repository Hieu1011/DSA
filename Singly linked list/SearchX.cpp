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
void CreateEmptyList(LIST& L)
{
    L.pHead = L.pTail = NULL;
}
void Addtail(LIST& L, int n)
{
    NODE* P = new NODE;
    P->info = n;
    P->pNext = NULL;
    if (L.pHead == NULL)
    {
        L.pHead = P;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = P;
        L.pTail = P;
    }
}
void CreateList(LIST& L)
{
    int n;
    cin >> n;
    while (n != -1)
    {
        Addtail(L, n);
        cin >> n;
    }
    cout << boolalpha;
}
bool searchX(NODE* L, int X)
{
    NODE* P = L;
    while (P != NULL)
    {
        if (P->info == X)
            return true;
        P = P->pNext;
    }
    return false;
}

int main() {
	LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	cout << searchX(L.pHead, X);

	return 0;
}