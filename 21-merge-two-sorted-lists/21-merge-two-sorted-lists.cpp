/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     //Using no external LL (Inplace merging)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
    
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        if(l2->val < l1->val)
            swap(l1,l2);
        
        ListNode*ans=l1;
        while(l1!=NULL and l2!=NULL)
        {
            ListNode*tmp=NULL;
            while(l1 and l1->val <= l2->val)
            {
                tmp=l1;
                l1=l1->next;
            }
            tmp->next=l2;
            swap(l1,l2);
        }
        return ans;
        
    }
};