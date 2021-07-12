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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //Count the no. of nodes in the LL
        int ct=0;
        ListNode*root=head;
        while(root!=NULL)
        {
            ct++;
            root=root->next;
        }
        if(n==ct)
            return head->next;
        // cout<<ct<<endl;
        root=head;
        int tmp=0;
        while(root!=NULL and tmp!=ct-n-1)
        {
            tmp++;
            root=root->next;
        }
        if(root->next!=NULL)
            root->next=root->next->next;
        cout<<tmp<<" "<<root->val;
        return head;
        
    }
};