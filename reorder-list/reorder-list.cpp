class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        for(auto iter = head; iter; iter = iter -> next)
            arr.push_back(iter);
        
		// pointers to start and end of list. Re-order in alternating fashion from both end
        int L = 1, R = size(arr)-1;
        for(int i = 0; i < size(arr); i++, head = head -> next) 
            if(i & 1)                             // odd iteration:
                head -> next = arr[L++];          //        - pick node from L & update L ptr
            else                                  // even iteration
                head -> next = arr[R--];          //        - pick node from R & update R ptr
        
        head -> next = nullptr;
    }
};