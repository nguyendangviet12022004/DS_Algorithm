#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
    int countSubArrySumEqualToK(vector<int> a,int k)
    {
        int curr = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i : a)
        {
            curr += i;
            ans += mp[curr-k];
            mp[curr] ++;
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    cout << sol.countSubArrySumEqualToK({0,1,1,2,2,0,0,1},2);
}
