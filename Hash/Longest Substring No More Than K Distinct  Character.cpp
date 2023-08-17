#include<iostream>
#include<string.h>
#include<set>
using namespace std;

class Solution
{
    public:
    string longestSubstr(string s,int k)
    {
        int l = 0;
        int r = 0;
        string ans = "";
        set<char> mp;
        for(;r < s.size();r++)
        {
            mp.insert(s[r]);
            while(mp.size() > k)
            {
                mp.erase(s[l++]);
            }
            if(r - l + 1 > ans.size()) ans = s.substr(l,r-l+1);
        }

        return ans;
    }
};

int main()
{
    Solution modu;
    string s = "abcedfffffffjkllllmnop";
    cout << modu.longestSubstr(s,5);
}
