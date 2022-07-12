/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,Node*>mp; //Shallow->Deep
        Node*tmp = head;
        while(tmp!=NULL)
        {
            mp[tmp]=new Node(tmp->val);
            tmp=tmp->next;
        }
        tmp = head;
        while(tmp!=NULL)
        {
            mp[tmp]->next = mp[tmp->next];
            mp[tmp]->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head];
    }
};