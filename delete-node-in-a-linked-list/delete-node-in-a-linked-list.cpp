/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        //Delete last node or tail node
        if(node->next==NULL)
        {
            node=NULL;
        }
        ListNode*tmp=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete(tmp);
    }
};