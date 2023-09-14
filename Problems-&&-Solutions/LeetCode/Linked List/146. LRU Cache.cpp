/*
Problem Statement: https://leetcode.com/problems/lru-cache/description/
*/

class LRUCache {
private:
    list<pair<int, int>> ls;
    unordered_map<int,list<pair<int, int>>::iterator> mp;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            ls.splice(ls.begin(), ls, mp[key]);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(mp.count(key)) {
            this->get(key);
            mp[key]->second = val;
        } else {
            ls.push_front({key, val});
            mp[key] = ls.begin();
        }

        // check if list length exceeds capacity
        if(ls.size() > capacity) {
            // key to be deleted
            int key_d = ls.back().first;
            ls.pop_back();
            mp.erase(key_d);
        }
    }
};
