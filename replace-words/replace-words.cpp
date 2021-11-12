struct Node{
    Node*links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch , Node*node){
        links[ch-'a']=node;
    }
    
    Node*getRef(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=1;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Solution {
private:
    
    Node* root;
    unordered_map<string,string>mp;
    
    void insert(string word)
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
    
    void search(string word)
    {
        Node*node=root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node->containsKey(word[i]))
                break;
            node=node->getRef(word[i]);
            if(node->isEnd())
            {
                mp[word]=word.substr(0,i+1);
                break;
            }
        }
        if(!mp.count(word))
            mp[word]=word;
    }
    
public:
    
    Solution(){
        root=new Node();
    }
    
    string replaceWords(vector<string>& dict, string sent) 
    {
        for(auto str : dict)
            insert(str);
        
        stringstream s(sent);
        string word;
        while(s>>word){
            search(word);
        }
        
        string ans="";
        stringstream t(sent);
        while(t>>word){
            ans+=mp[word];
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};