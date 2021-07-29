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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        //Find the len of the LL
        int cnt=0;
        ListNode*tmp=head;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            cnt++;
        }
        
        //Main process begins
        ListNode*dummy=new ListNode();
        dummy->next=head;
        ListNode*pre=dummy;
        ListNode*curr=head , *nex=head->next;
        while(cnt>=k)
        {
            int ct=0;
            while(ct!=k-1)
            {
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;
                ct++;
            }
            cnt-=k;
            pre=curr;
            curr=pre->next;
            if(!curr)
                break;
            nex=curr->next;
        }
        
        return dummy->next;
    }
};