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
    ListNode*merge(ListNode*l1 , ListNode*l2)
    {
        ListNode*dummy=new ListNode(0);
        ListNode*tmp=dummy;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                ListNode*newNode=new ListNode(l1->val);
                tmp->next=newNode;
                tmp=newNode;
                l1=l1->next;
            }
            else
            {
                ListNode*newNode=new ListNode(l2->val);
                tmp->next=newNode;
                tmp=newNode;
                l2=l2->next;
            }
        }
        while(l1!=NULL)
        {
            ListNode*newNode=new ListNode(l1->val);
            tmp->next=newNode;
            tmp=newNode;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            ListNode*newNode=new ListNode(l2->val);
            tmp->next=newNode;
            tmp=newNode;
            l2=l2->next;
        }
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode*slow=head, *fast=head ;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*node=slow->next;
        slow->next=NULL;
        ListNode*left=sortList(head);
        ListNode*right=sortList(node);
        return merge(left,right);
    }
};