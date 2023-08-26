#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
public:
    vector<vector<string>> groupAnagram(vector<string> words)
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(string s: words)
        {
            string t = s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        for(auto p: mp)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};
int main()
{

}
