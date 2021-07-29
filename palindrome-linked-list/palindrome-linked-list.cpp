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
    ListNode*findMiddle(ListNode*head)
    {
        ListNode*slow=head , *fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode*reverse(ListNode*head)
    {
        ListNode*dummy=NULL,*next=head;
        while(head!=NULL)
        {
            next=head->next;
            head->next=dummy;
            dummy=head;
            head=next;
        }
        return dummy;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        //Find the middle element of the LL
        ListNode*mid=findMiddle(head);
        
        
        //Reverse the right-half of the LL(right half after the mid node)
        mid->next=reverse(mid->next);
        
        
        //Put a dummy node at head and Increment mid by one and then compare both of them simultaneoulsy
        ListNode*dummy=head;
        mid=mid->next;
        while(mid!=NULL)
        {
            if(mid->val!=dummy->val)
                return false;
            mid=mid->next;
            dummy=dummy->next;
        }
        return true;
    }
};