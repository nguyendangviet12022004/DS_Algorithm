// Problems : Temp[] : temp[i] is temperature of day i
// Answer : Ans[]: ans[i] is how many day we need to wait to the next day which have greater temperature

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> solve(vector<int> temp)
{
    stack<int> st;
    vector<int> ans (temp.size(),0);
    for(int i = 0;i < temp.size();i ++)
    {
        while(!st.empty() && temp[st.top()] < temp[i])
        {
            ans[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> a = {34, 33, 32, 31, 30, 50};
    vector<int> b = solve(a);
    for(int x : b) cout << x << " ";
}
