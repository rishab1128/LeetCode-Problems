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
        ListNode*entry=head;
        while(entry!=slow)
        {
            entry=entry->next;
            slow=slow->next;
        }
        return slow;
    }
};