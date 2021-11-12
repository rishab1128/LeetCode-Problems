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
    ListNode* removeElements(ListNode* mainHead, int val) 
    {
        ListNode*head=mainHead;
        
        //val present at the starting of the list
        while(head!=NULL and head->val==val)
            head=head->next;
        
        mainHead=head;
        
        
        while(head!=NULL)
        {
            ListNode*nxt=head->next;
            while(nxt!=NULL and nxt->val==val)
                nxt=nxt->next;
            head->next=nxt;
            head=head->next;
        }
        
        return mainHead;
        
    }
};