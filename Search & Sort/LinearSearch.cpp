#include <iostream>
#define MAXN 400000

using namespace std;
void NhapMang(int a[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int LinearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}
int main()
{
    int a[MAXN], n, x;
    std::cin >> x;
    NhapMang(a, n);
    int i = LinearSearch(a, n, x);
    if (i == -1) std::cout << "false";
    else std::cout << "true";
    return 0;
}
