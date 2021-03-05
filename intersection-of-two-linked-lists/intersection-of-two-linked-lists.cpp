#include<bits/stdc++.h>
using namespace std;

// struct ListNode 
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    //Approach 1 -> Using Hash Map
    //TC: O(N+M) ; SC: O(N)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        map<ListNode*,int>mp;
        ListNode*ans=NULL;
        while(headA!=NULL)
        {
            mp[headA]=1;
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            if(mp[headB])
            {
                ans=headB;
                break;
            }
            headB=headB->next;
        }
        return ans;
        
    }
};