#include<iostream>
#include<stack>
#define ff(i,a,b,s) for(int i = a;i <=b ;i+=s)
#define fl(i,a,b,s) for(int i = a;i >=b ;i -=s)

using namespace std;
// Function to return precedence of operators
int prec(char c)
{
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    return -1;
}

string postFix(string s)
{
    stack<char> st;
    string res = "";

    ff(i,0,s.size()-1,1)
    {
        char c = s[i];
        if(c == ' ') continue;
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))   res += c; // element
        else if(c == '(') st.push(c);
        else if(c == ')')
        {
            while(st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(c) <= prec(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
int main()
{
    string s;
    getline(cin,s);
    cout << postFix(s);
}
