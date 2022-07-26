/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode*hasCycle(ListNode*head)
    {
        if(!head or !head->next)
            return NULL;
        ListNode*slow=head , *fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return slow;
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode*slow=hasCycle(head);
        if(!slow)
            return slow;
        
        cout<<slow->val<<endl;
        
        ListNode*entry=head;
        //Removing loop in a LL
        if(slow==entry)
        {
            while(slow->next!=entry)
                slow=slow->next;
            return slow->next;
        }
        while(entry->next!=slow->next)
        {
            entry=entry->next;
            slow=slow->next;
        }
        //cout<<slow->val<<endl;
        
        return slow->next;
    }
};