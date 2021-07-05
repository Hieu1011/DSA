#include <iostream>
#include <math.h>
using namespace std;
#define MAXN 400

void NhapMang(int A[], const int& N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int interpolation_search(int* a, int n, int x)
{
    int l=0, r = n - 1;
    while (l <= r)
    {
        int RD = a[r] - a[l];
        int ID = r - l;
        int VD = x - a[l];
        if (VD < 0)
            return -1;
        if (RD <= 0)
            return (a[l] == x ? l : -1);
        float f = float(ID) / RD;
        int m = l + floor(VD * f);
        if (a[m] < x)
            l = m + 1;
        else if (a[m] > x)
            r = m - 1;
        else return m;
    }
}

int main() {
    int x; cin >> x;
    int n; cin >> n;

    int a[MAXN];
    NhapMang(a, n);

    int i = interpolation_search(a, n, x);

    if (i == -1) std::cout << "false";
    else std::cout << "true";

    return 0;
}

