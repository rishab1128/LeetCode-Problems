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
        int cnt = 0;
        ListNode*tmp = head;
        while(tmp!=NULL and cnt<k)
        {
            tmp = tmp->next;
            cnt++;
        }
        if(cnt<k)
            return head;
        
        ListNode*future = reverseKGroup(tmp,k);
        ListNode*curr=head ,  *prev=NULL , *next=NULL;
        cnt = 0;
        while(cnt<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        head->next = future;
        return prev;
    }
};