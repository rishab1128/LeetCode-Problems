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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode*root=head;
        while(root!=NULL)
        {
            if(root!=NULL and root->next!=NULL)
            {
                int tmp=root->val;
                root->val=root->next->val;
                root->next->val=tmp;
                root=root->next->next;
                
            }     
            if(root!=NULL and root->next==NULL)
                break;
        }
        return head;
        
    }
};