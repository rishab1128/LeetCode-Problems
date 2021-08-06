class LRUCache {
public:
    //Structure of the Doubly Linked List Node
    class node{
        public:
            int key;
            int val;
            node*next;
            node*prev;
            node(int _key , int _val){
                key=_key;
                val=_val;
            }
    };
    
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* newNode){
        node*nxt=head->next;
        newNode->next=nxt;
        newNode->prev=head;
        head->next=newNode;
        nxt->prev=newNode;
    }
    
    void deleteNode(node* delNode){
        node*delPrev=delNode->prev;
        node*delNext=delNode->next;
        delNext->prev=delPrev;
        delPrev->next=delNext;
        delete(delNode);
    }
    
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        int value=mp[key]->val;
        
        node*delNode=mp[key];
        deleteNode(delNode);
        node*newNode=new node(key,value);
        addNode(newNode);
        mp[key]=newNode;
        
        return value;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)==mp.end()) 
        {
            if(cap==0)
            {
                //Delete the node just prev to tail from the hashmap first and then from the DLL
                //And then add the newNode in both in the DLL and the hashmap
                node*delNode=tail->prev;
                mp.erase(delNode->key);
                deleteNode(delNode);
                node*newNode=new node(key,value);
                addNode(newNode);
                mp[key]=newNode;
                
            }
            else if(cap>0)
            {
                //Simply Add the newNode in both in the DLL and the hashmap
                //Update the variable cap
                node*newNode=new node(key,value);
                addNode(newNode);
                mp[key]=newNode;
                cap--;
            }
        }
        else
        {
            //Get the node address of the key from the map and then delete it from the DLL
            //And then add a newNode with the same key and updated value in the DLL
            //Update the node address of the key in the map
            node*delNode=mp[key];
            deleteNode(delNode);
            node*newNode=new node(key,value);
            addNode(newNode);
            mp[key]=newNode;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */