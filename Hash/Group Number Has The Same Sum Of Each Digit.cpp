// Group Numbers that  has the same sum of each digit

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public :
    int sum(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int> nums)
    {
        unordered_map<int,int> mp;
        int ans = -1;
        for(int x : nums)
        {
            int s = sum(x);
            if(mp.find(s) != mp.end()) ans = max(ans, mp[s] + x);
            mp[s] = max(mp[s],x);
        }
        return ans;
    }
};
