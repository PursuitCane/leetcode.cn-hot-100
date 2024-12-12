class LRUCache {
public:
    struct item {
        int val;
        list<int>::iterator it;
    };
    unordered_map<int, struct item*> mp;
    list<int> l;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (mp.count(key) <= 0) return -1;
        int ret = mp[key]->val;
        auto it = mp[key]->it;
        l.erase(it);
        l.push_front(key);
        mp[key]->it = l.begin();
        return ret;
    }
    
    void put(int key, int value) {
        if (mp.count(key) > 0) {
            mp[key]->val = value;
            auto it = mp[key]->it;
            l.erase(it);
            l.push_front(key);
            mp[key]->it = l.begin();
        } else {
            if (size == mp.size()) {
                int old_key = l.back();
                l.pop_back();
                l.push_front(key);
                auto* item = mp[old_key];
                item->val = value;
                item->it = l.begin();
                mp.erase(old_key);
                mp[key] = item;
            } else {
                struct item* pair = new item;
                pair->val = value;
                l.push_front(key);
                pair->it = l.begin();
                mp[key] = pair;
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
