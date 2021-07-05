#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
int binary_search(int a[], int n, int x)
{
    int l = 0, t, r;
    r = n - 1;
    while (true)
    {
        if (l > r)
            return -1;
        t = (l + r) / 2;
        if (a[t] == x)
            return t;
        else
        {
            if (x < a[t])
                r = t - 1;
            else
                l = t + 1;
        }
    }
}
int main() 
{
    int x, n, a[MAXN];
    cin >> x;
    cin >> n;
    NhapMang(a, n);
    int i = binary_search(a, n, x);
    if (i == -1) std::cout << "false";
    else std::cout << "true";
    return 0;
}

