class Trie {
    Trie* chars[26]{};
    bool endsHere = false;
public:    
    void insert(string& s) {                              // inserts a string in Trie
        auto cur = this;
        for(int i = size(s)-1; ~i; i--) {                 // insert in reverse order
            if(!cur -> chars[s[i]-'a'])
                cur -> chars[s[i]-'a'] = new Trie();      // add new node for current character
            cur = cur -> chars[s[i]-'a'];                 // move to that character's node
        }
        cur -> endsHere = true;                           // mark that a word ends at this node
    }
    bool search(string& s) {                              // searches for a suffix of string
        auto cur = this;
        for(int i = size(s)-1; ~i; i--) {
            if(!cur -> chars[s[i]-'a']) return false;     // no letter-link to next character exists
            cur = cur -> chars[s[i]-'a'];
            if(cur -> endsHere) return true;              // found a  word ending at this node => suffix of s found in Trie
        }
        return false;
    }
};
class StreamChecker {
    Trie *T = new Trie();
    string queryStream = "";
public:
    StreamChecker(vector<string>& words) {
        for(auto& w : words) T -> insert(w);
    }
    
    bool query(char c) {
        queryStream += c;                                  // add new character to query stream
        return T -> search(queryStream);                   // and search for any suffix in Trie
    }
};