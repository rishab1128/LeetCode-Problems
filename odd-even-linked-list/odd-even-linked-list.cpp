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
    
    int numOfNodes(ListNode*head)
    {
        ListNode*tmp=head;
        int cnt=0;
        while(tmp!=NULL)
        {
            cnt++;
            tmp=tmp->next;
        }
        return cnt;
    }
    
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;
    
        ListNode*tmp=head;
        ListNode*secondNode=tmp->next;
        int n=numOfNodes(head);
        if(n%2)
        {
            while(tmp->next!=NULL)
            {
                ListNode*node=tmp->next;
                tmp->next=tmp->next->next;
                tmp=node;
            }
            tmp->next=secondNode;
        }
        else
        {
            while(tmp->next->next!=NULL)
            {
                ListNode*node=tmp->next;
                tmp->next=tmp->next->next;
                tmp=node;
            }
            tmp->next=secondNode;
        }
        return head;
        
    }
};