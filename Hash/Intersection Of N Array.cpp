#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
using namespace std;
class Solution
{
    vector<int> intersection(vector<vector<int>> m)
    {
        unordered_map<int,int> mp;
        for(vector<int> a : m)
            for(int i : a)
                mp[i]++;

        int n = m.size();
        vector<int> res;
        for(auto p : mp)
            if(p.second == n) res.push_back(p.first);

        sort(res.begin(),res.end());
        return res;
    }
};

int main()
{

}
