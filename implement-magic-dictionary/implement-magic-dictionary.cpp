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


class MagicDictionary {
private : Node*root;
public:
    MagicDictionary() 
    {
        root=new Node();
    }
    
    void insert(string word)
    {
        Node*node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->getRef(word[i]);
        }
        node->setEnd();
    }
    
    void buildDict(vector<string> dict) 
    {
        for(auto str : dict)
            insert(str);
    }
    
    bool searchInTrie(string word) 
    {
        Node*node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node=node->getRef(word[i]);
        }
        return node->isEnd();
    }
    
    bool search(string word)
    {
        
        int n=word.size();
        for(int i=0; i<n; i++)
        {
            string tmp=word;
            for(char ch='a'; ch<='z'; ch++)
            {
                if(ch!=word[i]){
                    tmp[i]=ch;
                    if(searchInTrie(tmp))
                        return true;
                }
                
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */