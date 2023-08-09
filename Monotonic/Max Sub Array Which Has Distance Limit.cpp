#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int solve(vector<int> arr, int limit)
{
    deque<int> decreas;
    deque<int> increas;
    int len = arr.size();
    int l = 0;
    int ans = 0;
    for(int r = 0 ;r < len ;r ++)
    {
        while(!decreas.empty() && arr[r] > decreas.back()) decreas.pop_back();

        while(!increas.empty() && arr[r] < increas.back()) increas.pop_back();

        decreas.push_back(arr[r]);
        increas.push_back(arr[r]);

        while(decreas.front() - increas.front() > limit)
        {
            if(decreas.front() == arr[l]) decreas.pop_front();
            if(increas.front() == arr[l]) increas.pop_front();
            l++;
        }

        ans = max(ans,r - l + 1);
    }
    return ans;
}
int main()
{
    cout << solve({12,3,4,6,9,11},7);
}
