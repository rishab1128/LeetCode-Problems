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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        if(head==NULL)
            return {-1,-1};
        vector<int>pos;
        int last=head->val , idx=1;
        ListNode*newHead=head->next;
        while(newHead->next!=NULL)
        {
            int prev=last, next=newHead->next->val, curr=newHead->val;
            if(curr>prev and curr>next)
                pos.push_back(idx);
            else if(curr<prev and curr<next)
                pos.push_back(idx);
            idx++;
            last=curr;
            newHead=newHead->next;
        }
        if(pos.size()<2)
            return {-1,-1};
        
        int m=pos.size();
        int mini=INT_MAX;
        for(int i=0; i<m-1; i++)
            mini=min(mini,pos[i+1]-pos[i]);
        int maxi=pos[m-1]-pos[0];
        return {mini , maxi};
    }
};