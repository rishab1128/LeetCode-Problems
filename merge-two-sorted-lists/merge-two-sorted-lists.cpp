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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        //Using external LL
        ListNode*dummy=new ListNode();
        ListNode*dup_dummy=dummy;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val > l2->val)
            {
                ListNode* new_node = new ListNode(l2->val);
                dup_dummy->next = new_node;
                dup_dummy = new_node;
                l2=l2->next;
            }
            else
            {
                ListNode* new_node = new ListNode(l1->val);
                dup_dummy->next = new_node;
                dup_dummy = new_node;
                l1=l1->next;
            }
        }
        while(l1!=NULL)
        {
            ListNode* new_node = new ListNode(l1->val);
            dup_dummy->next = new_node;
            dup_dummy = new_node;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            ListNode* new_node = new ListNode(l2->val);
            dup_dummy->next = new_node;
            dup_dummy = new_node;
            l2=l2->next;
        }
        return dummy->next;
        
    }
};