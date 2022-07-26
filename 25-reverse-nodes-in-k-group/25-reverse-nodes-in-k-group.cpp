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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int ct = 0;
        ListNode*tmp = head;
        while(tmp and ct<k)
        {
            tmp = tmp->next;
            ct++;
        }
        if(ct<k)
            return head;
        
        ListNode*future = reverseKGroup(tmp,k);
        
        ct = 0;
        ListNode*prev = NULL , *curr = head, *next = NULL;
        while(ct<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ct++;
        }
        head->next = future;
        return prev;
        
    }
};