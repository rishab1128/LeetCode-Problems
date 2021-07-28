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
        int carry=0;
        ListNode*dummy=new ListNode();
        ListNode*tmp=dummy;
        while(l1!=NULL || l2!=NULL || carry>0)
        {
            int sum=0;
            if(l1 and l2)
                sum=l1->val+l2->val+carry;
            else if(l1)
                sum=l1->val+carry;
            else if(l2)
                sum=l2->val+carry;
            else
                sum=carry;
            
            ListNode*new_node = new ListNode(sum%10);
            tmp->next=new_node;
            tmp=new_node;
            
            carry=sum/10;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        return dummy->next;
        
    }
};