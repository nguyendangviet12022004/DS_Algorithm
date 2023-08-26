// how many cards to pick so that at least 1 card is duplicate
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public :
    int minimunCardPickUp(vector<int> cards)
    {
        unordered_map<int,int> mp;
        int ans = 100000000x;
        int n = cards.size();
        for(int i = 0; i < n;i ++)
        {
            if(mp.find(cards[i]) != mp.end()) ans = min(ans, i - mp[cards[i]]);
            mp[cards[i]] = i;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol. minimunCardPickUp({1,2,3,4,1,2,5,6,5});
}
