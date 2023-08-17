#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    int countSubArryHasKOdd(vector<int> a, int k)
    {
        int curr = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        for(int x : a)
        {
            curr += x % 2;
            ans += mp[curr - k];
            mp[curr] ++;
        }
        return ans;
    }
};
int main()
{

}
