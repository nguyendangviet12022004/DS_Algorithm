#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution{
public :
    vector<int> twoSum(vector<int> a, int s)
    {
        unordered_map<int,int> mp;
        int n = a.size();
        for(int i = 0 ;i < n;i++)
        {
            if(mp.find(s-a[i]) != mp.end())
            {
                cout << mp[s-a[i]] << " " << i ;
                return {mp[s-a[i]],i};
            }
            mp[a[i]] = i;
        }
    }
};
int main()
{
    Solution modue1;
    vector<int> a = {1,2,3,4,5,6,7,8};
    int s = 10;
    modue1.twoSum(a,10);
}
