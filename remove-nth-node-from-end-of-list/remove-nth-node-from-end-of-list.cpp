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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        //Using slow and fast pointers
        ListNode*dummy=head;
        ListNode*slow=dummy , *fast=dummy;
        int ct=0;
        while(ct!=n)
        {
            fast=fast->next;
            ct++;
        }
        if(!fast)
            return dummy->next;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummy;
        
    }
};