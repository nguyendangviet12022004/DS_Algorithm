#include<iostream>
#include<vector>
#include<deque>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
using namespace std;

vector<int> solve(vector<int> a, int k)
{
    vector<int> ans;
    deque<int> dq;

    ff(i, 0, a.size()-1 , 1)
    {
        while(!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
        dq.push_back(i);

        if(dq.front() + k == i) dq.pop_front();

        if(i >= k - 1) ans.push_back(a[dq.front()]);
    }
    return ans;
}


int main()
{
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> dq = solve(a,k);
    for(int x : dq) cout << x << " ";
}
