#include <iostream>
using namespace std;
#define MAXN 100

struct NODE {
    char info;
    NODE* pNext;
};

NODE* CreateNode(char x) {
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
void push(stack& s, char x) {
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
char& top(stack s) {
    return s.top->info;
}
int Uutien(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return -1;
}
bool isOperator(char x)
{
    return ((x == '-') || (x == '+') || (x == '*') || (x == '/') || (x == '^'));
}
void Input_infix(char infix[], int& ni)
{
    ni = 0;
    cin >> infix[ni];
    while (infix[ni] != '#')
    {
        ni++;
        cin >> infix[ni];
    }
}
void infix_to_postfix(char infix[], int ni, char postfix[], int &np)
{
    stack s;
    CreateEmptyStack(s);
    np = 0;
    char c;
    char temp;
    for (int i = 0; i < ni; i++)
    {
        c = infix[i];
        if (c >= '0' && c <= '9')
        {
            postfix[np++] = c;
        }
        else if (c == '(')
        {
            push(s, c);
            continue;
        }
        else if (c == ')')
        {
            while (empty(s) == 0 && top(s) != '(')
            {
                postfix[np++] = top(s);
                pop(s);
            }
            pop(s);
            continue;
        }
        else
        {
            while (s.top != NULL && Uutien(top(s)) >= Uutien(c))
            {
                postfix[np++] = top(s);
                pop(s);
            }
            push(s, c);
        }
    }
    while (s.top!=NULL)
    {
        postfix[np++] = top(s);
        pop(s);
    }
}

void Output(char postfix[], int np) 
{
    for (int i = 0; i < np; i++)
        cout << postfix[i] << " ";
}
int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}


