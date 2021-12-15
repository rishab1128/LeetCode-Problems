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
    int count(ListNode*head)
    {
        int ct=0;
        while(head!=NULL)
        {
            ct++;
            head=head->next;
        }
        return ct;
    }
    
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode*hd1=head;
        int n=count(head);
        while(n>0)
        {
            ListNode*hd2=hd1;
            while(hd2->next!=NULL)
            {
                if(hd2->val > hd2->next->val)
                {
                    int tmp=hd2->val;
                    hd2->val=hd2->next->val;
                    hd2->next->val=tmp;
                }
                hd2=hd2->next;
            }
            n--;
        }
        return head;
    }
};