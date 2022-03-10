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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode*dummy=new ListNode();
        ListNode*tmp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int sum=0;
            if(l1 and l2)
            {
                sum=l1->val+l2->val+carry;
                int value=sum%10;
                carry=sum/10;
                ListNode*node=new ListNode(value);
                tmp->next=node;
                tmp=node;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1)
            {
                sum=l1->val+carry;
                int value=sum%10;
                carry=sum/10;
                ListNode*node=new ListNode(value);
                tmp->next=node;
                tmp=node;
                l1=l1->next;
            }
            else if(l2)
            {
                sum=l2->val+carry;
                int value=sum%10;
                carry=sum/10;
                ListNode*node=new ListNode(value);
                tmp->next=node;
                tmp=node;
                l2=l2->next;
            }
            else
            {
                ListNode*node=new ListNode(carry);
                tmp->next=node;
                tmp=node;
                carry=0;
            }
            
        }
        return dummy->next;
        
    }
};