// Type a calculus from user such as : (1 + 1) * 2


#include<iostream>
#include<stack>
#define ff(i, a, b, s) for(int i = a; i <= b; i += s)
#define fl(i, a, b ,s) for(int i = a; i >= b; i -= s)

using namespace std;

// function return precedence of each operator
int prec(char x)
{
    if(x == '*' || x == '/') return 2;

    if(x == '+' || x == '-') return 1;
    return 0;
}

// Apply perform arithmetic operator

int calc(int a, int b , char op)
{
    switch(op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}


// solve function
int solve(string s)
{
    int len = s.size();
    stack<int> num;
    stack<int> op;

    ff(i , 0 , len - 1 , 1)
    {
        char c = s[i];
        if (c == ' ') continue;
        else if(isdigit(c))
        {
            int val = 0;
            while(i < len && isdigit(s[i]))
            {
                val = val * 10 + (s[i] - '0');
                i ++;
            }
            num.push(val);
            i --;
        }
        else if(c == '(') op.push(c);
        else if(c == ')')
        {
            while(op.top() != '(')
            {
                char oper = op.top();
                op.pop();

                int b = num.top();
                num.pop();

                int a = num.top();
                num.pop();

                num.push(calc(a,b,oper));
            }
            op.pop();
        }
        else
        {
            while(!op.empty() && prec(c) <= prec(op.top()))
            {
                char oper = op.top();
                op.pop();

                int b = num.top();
                num.pop();

                int a = num.top();
                num.pop();

                num.push(calc(a,b,oper));
            }
            op.push(c);
        }
    }

    while(!op.empty())
    {
            char oper = op.top();
            op.pop();

            int b = num.top();
            num.pop();

            int a = num.top();
            num.pop();

            num.push(calc(a,b,oper));

    }
    return num.top();
}


int main()
{
    string s;
    getline(cin,s);
    cout << solve(s);
}
