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
        ListNode*node = head;
        int num=0;
        while(node!=NULL)
        {
            num++;
            node=node->next;
        }
        int ct=0;
        ListNode*temp=head;
        while(ct!=num/2)
        {
            ct++;
            temp=temp->next;
        }
        
        ListNode*rev=NULL;
        // cout<<temp->val<<endl;
        
        if(num%2==0)
            rev = reverse(temp);
        else
            rev = reverse(temp->next);
        
        node=head;
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