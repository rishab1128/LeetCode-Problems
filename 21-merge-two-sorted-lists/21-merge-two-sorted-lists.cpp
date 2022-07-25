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
    //Using external LL
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode*ans = new ListNode();
        ListNode*tmp = ans;
        
        while(list1 and list2)
        {
            ListNode*newNode = new ListNode();
            if(list1->val<=list2->val){
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                newNode->val = list2->val;
                list2 = list2->next;
            }
               
            tmp->next = newNode;
            tmp = tmp->next;
        }
        while(list1)
        {
            ListNode*newNode = new ListNode();
            newNode->val = list1->val;
            tmp->next = newNode;
            tmp = tmp->next;
            list1 = list1->next;
        }
        while(list2)
        {
            ListNode*newNode = new ListNode();
            newNode->val = list2->val;
            tmp->next = newNode;
            tmp = tmp->next;
            list2 = list2->next;
        }
        return ans->next;
        
        
    }
};