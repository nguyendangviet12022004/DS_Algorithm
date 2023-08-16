#include<iostream>
#include<unordered_set>
using namespace std;
class Solution{
public:
    char duplicteCharacter(string s)
    {
        unordered_set<char> container;
        for(char x : s)
        {
            if(!container.count(x)) container.insert(x);
            else return x;
        }
        return ' ';
    }
};

int main()
{
    string s = "vietnamdanchuconghoa";
    Solution module;
    cout << module.duplicteCharacter(s);
}
