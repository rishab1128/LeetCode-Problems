struct Node{
    Node*links[26];
    bool flag=false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch , Node*node)
    {
        links[ch-'a']=node;
    }
    
    Node*getRef(char ch)
    {
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=1;
    }
    
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private: Node*root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) 
    {
        Node*node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i] , new Node());
            node=node->getRef(word[i]);
        }
        node->setEnd();   
    }
    
    bool recur(string word , int i, Node*root)
    {
        if(i==word.size() and root->isEnd())
            return true;
        
        else if(i>=word.size())
            return false;
        
        if(word[i]!='.' and !root->containsKey(word[i]))
            return false;
        
        else if(word[i]!='.' and root->containsKey(word[i]))
        {
            return recur(word , i+1 , root->getRef(word[i]));
        }
            
        bool tmp=false;
        for(int j=0; j<26; j++)
        {
            if(root->links[j]!=NULL)
                tmp|=recur(word , i+1 , root->links[j]);
        }
        
        return tmp;
    }
    
    bool search(string word) 
    {
        Node*node=root;
        return recur(word, 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */