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
        ListNode*curr=head , *prev=NULL ,*front=NULL;
        while(curr)
        {
            front = curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode*node = head , *slow=head, *fast=head , *temp=NULL;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        temp=slow;
        
        ListNode*rev=NULL;
        // cout<<temp->val<<endl;
        
        rev = reverse(temp);
        
        while(rev!=NULL)
        {
            if(node->val==rev->val)
            {
                node=node->next;
                rev=rev->next;
            }
            else
                return false;
        }
        
        return true;
    }
};