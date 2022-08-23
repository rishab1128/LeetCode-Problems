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
    
    ListNode*reverse(ListNode*head)
    {
        ListNode*curr = head , *prev = NULL , *next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode*recurReverse(ListNode*head)
    {
        if(!head || !(head->next))
            return head;
        
        ListNode*rem = recurReverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rem;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode*slow = head , *fast = head;
        while(fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* mid = slow;
        
        ListNode*rev  = reverse(mid);
        
        ListNode*tmp = head;
        while(rev)
        {
            if(rev->val==tmp->val)
            {
                rev = rev->next;
                tmp = tmp->next;
            }
            else
                return false;
        }
        return true;
    }
};