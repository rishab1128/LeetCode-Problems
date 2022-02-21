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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode*ans=new ListNode();
        ListNode*curr=ans;
        while(head!=NULL)
        {
            int tmp=0;
            while(head->next!=NULL and head->next->val!=0)
            {
                tmp+=head->val;
                head=head->next;
            }
            tmp+=head->val;
            head=head->next;
            curr->val=tmp;
            if(head->next==NULL)
            {
                curr->next=NULL;
                break;
            }
            curr->next=new ListNode();
            curr=curr->next;
        }
        return ans;
        
    }
};