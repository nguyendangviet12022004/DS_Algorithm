#inlcude<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int intersection(vector<vector<int>> m)
    {
        int n = m.size();
        unordered_map<vector<int>, int> mp1;
        unordered_map<vector<int>, int> mp2;
        for(vector<int> v: m) mp1[v] ++;
        for(int j = 0 ;j < n;j ++)
        {
            vector<int> v;
            for(int i = 0; i < n;i ++)
            {
                v.push_back(m[i][j]);
            }
            mp2[v] ++;
        }
        int ans = 0;
        for(auto a: mp1)
        {
            ans += a.second * mp2[a.first];
        }
        return ans;
    }
};
