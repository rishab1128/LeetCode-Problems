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
    
    pair<ListNode*,ListNode*> reverseLL(ListNode*head ,  ListNode*end)
    {
        ListNode*prev=NULL , *curr = head ,  *next = NULL;
        while(prev!=end)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // cout<<prev<<" "<<end<<endl;
        // cout<<prev->val<<" "<<curr->val<<endl;
        return {prev,curr};
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left==right)
            return head;
        ListNode*start = NULL , *end = NULL, *last=NULL;
        ListNode* tmp = head;
        int ct = 1;
        while(tmp)
        {
            if(ct==left-1)
                last = tmp;
            else if(ct==left)
                start = tmp;
            else if(ct==right)
                end = tmp;
            tmp = tmp->next;
            ct++;
        }
        // cout<<start->val<<" "<<end->val<<endl;
        
        auto rev = reverseLL(start,end);
        if(last)
            last->next = rev.first;
        start->next = rev.second;
        
        return left==1 ? rev.first : head;
        
    }
};