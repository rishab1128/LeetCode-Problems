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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next)
            return head;
        int len=0;
        ListNode*tmp=head;
        ListNode*lastNode=NULL;
        while(tmp!=NULL)
        {
            if(tmp->next==NULL)
                lastNode=tmp;
            len++;
            tmp=tmp->next;
        }
        
        k=k%len;
        if(k==0)
            return head;
        
        int ct=0;
        tmp=head;
        while(ct!=len-k-1)
        {
            tmp=tmp->next;
            ct++;
        }
        lastNode->next=head;
        head=tmp->next;
        tmp->next=NULL;
        return head;
    }
};