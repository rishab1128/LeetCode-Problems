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
    //Solution inspired from @fudonglai -> see the 1st comment in the Soln tab
    ListNode*successor;
    ListNode* reverse_First_N_nodes(ListNode*head, int n)
    {
        if(n==1)
        {
            successor=head->next;
            return head;
        }
        ListNode*last=reverse_First_N_nodes(head->next, n-1);
        head->next->next=head;
        head->next=successor;
        return last;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        successor=NULL;
        if(left==1)
        {
            return reverse_First_N_nodes(head,right);
        }
        head->next=reverseBetween(head->next,left-1,right-1);
        return head;
    }
};