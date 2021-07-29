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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode*dummy1=headA , *dummy2=headB;
        while(dummy1!=NULL or dummy2!=NULL)
        {
            //cout<<dummy1->val<<" "<<dummy2->val<<endl;
            if(dummy1==dummy2)
                return dummy1;
            dummy1=dummy1->next;
            dummy2=dummy2->next;
            if(!dummy1 and !dummy2)
                break;
            if(!dummy1)
                dummy1=headB;
            if(!dummy2)
                dummy2=headA;
        }
        return NULL;
        
    }
    
};