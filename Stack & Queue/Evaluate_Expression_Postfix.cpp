#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE {
    float info;
    NODE* pNext;
};

NODE* CreateNode(float x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
struct stack {
    NODE* top;
};
bool empty(const stack& s) {
    return (s.top == NULL);
}
void CreateEmptyStack(stack& s) {
    s.top = NULL;
}
void push(stack& s, float x) {
    NODE* p = CreateNode(x);
    if (s.top == NULL) s.top = p;
    else {
        p->pNext = s.top;
        s.top = p;
    }
}
void pop(stack& s) {
    if (s.top == NULL) return;
    NODE* p = s.top;
    s.top = s.top->pNext;
    delete p;
}
float& top(stack s) {
    return s.top->info;
}
bool isOperator(char x) {
    return ((x == '-') || (x == '+') || (x == '*') || (x == '/') || (x == '^'));
}
bool isBracket(char x) {
    return ((x == '(') || (x == ')'));
}
void InputPostFix(char postix[], int& n) {
    char k;
    cin >> k;
    n = 0;
    while (k != '#') {
        postix[n++] = k;
        cin >> k;
    }
}
float evaluate_expression(char a[], int np)
{
    float temp1, temp2;
    stack s;
    CreateEmptyStack(s);
    NODE* p = s.top;
    for (int i = 0; i < np; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
            push(s, a[i] - 48);
        else if (a[i] == '+')
        {
            temp1 = p->info;
            p = p->pNext;
            temp2 = p->info;
            pop(s);
            pop(s);
            push(s, temp1 + temp2);
        }
        else if (a[i] == '-')
        {
            temp1 = p->info;
            p = p->pNext;
            temp2 = p->info;
            pop(s);
            pop(s);
            push(s, temp2 - temp1);
        }
        else if (a[i] == '*')
        {
            temp1 = p->info;
            p = p->pNext;
            temp2 = p->info;
            pop(s);
            pop(s);
            push(s, temp1 * temp2);
        }
        else if (a[i] == '/')
        {
            temp1 = p->info;
            p = p->pNext;
            temp2 = p->info;
            pop(s);
            pop(s);
            push(s, temp2 / temp1);
        }
        else
        {
            temp1 = p->info;
            p = p->pNext;
            temp2 = p->info;
            pop(s);
            pop(s);
            push(s, pow(temp2, temp1));
        }
        p = s.top;
    }

    return top(s);
}

int main() {
    char postfix[MAXN];
    int np;

    InputPostFix(postfix, np);
    // Output(postfix, np);

    cout.precision(3);
    cout << evaluate_expression(postfix, np);

    return 0;
}
