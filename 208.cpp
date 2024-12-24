class Trie {
public:
    struct node {
        bool is_end;
        vector<node*> values;
        node() { 
            is_end = false; 
            values.resize(26); 
        }
    };

    struct node* handle;
    Trie() {
        handle = new node();
        handle->is_end = false;
    }
    
    void insert(string word) {
        node* curr = handle;
        for (char ch : word) {
            if (curr->values[ch - 'a'] == nullptr) {
                curr->values[ch - 'a'] = new node();
                curr = curr->values[ch - 'a'];
            } else {
                curr = curr->values[ch - 'a'];
            }
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        node* curr = handle;
        for (char ch : word) {
            if (curr->values[ch - 'a'] == nullptr) return false;
            curr = curr->values[ch - 'a'];
        }
        return curr->is_end;
        
    }
    
    bool startsWith(string prefix) {
        node* curr = handle;
        for (char ch : prefix) {
            if (curr->values[ch - 'a'] == nullptr) return false;
            curr = curr->values[ch - 'a'];
        }
        return true;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
