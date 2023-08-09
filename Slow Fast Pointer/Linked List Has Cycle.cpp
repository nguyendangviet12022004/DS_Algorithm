#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val) : val(val) , next(nullptr);
};

bool hasCycle(Node* root)
{
    Node* fast = root;
    Node* slow = root;
    while(fast && fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast ==  slow) return true;
    }
    return false;
}

int main()
{

}
