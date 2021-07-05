
#include <iostream>
#include <math.h>

using namespace std;
#define MAXN 400

void NhapMang(int A[], const int& N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
int Bs(int a[], int l, int r, int x)
{
    int t;
    if (l > r)
        return -1;
    t = (l + r) / 2;
    if (a[t] == x)
        return t;
    else
    {
        if (x < a[t])
            return Bs(a, l, t - 1, x);
        else
            return Bs(a, t + 1, r, x);
    }
}
int binary_search(int a[], int n, int x)
{
    int l = 0, t, r;
    r = n - 1;
    return Bs(a, l, r, x);
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i = binary_search(a, n, x);

    if (i == -1) std::cout << "false";
    else std::cout << "true";

    return 0;
}


