/*
Problem Statement: https://leetcode.com/problems/lfu-cache/description/
*/

class LFUCache {
private:
    unordered_map<int, list<pair<int, int>>> lfu; // {keyFrequency, lru}
    unordered_map<int, list<pair<int, int>>::iterator> mp; // {key, iterator to the pair (key, val) in lru}
    unordered_map<int, int> keyFreq; // {key and its frequency}
    int capacity, lfCnt; // least frequency count available

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        lfCnt = 0;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            this->put(key, mp[key]->second);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int val) {
        // IF THE KEY ALREADY EXISTED
        if(mp.count(key)) {
            // current frequency of the key
            int currFq = keyFreq[key];

            // remove this key from current fq's lru list and mp
            lfu[currFq].erase(mp[key]);
            mp.erase(key);

            // update the frequency
            ++keyFreq[key];

            // insert into new fq's lru list and mp
            lfu[keyFreq[key]].push_front({key, val});
            mp[key] = lfu[keyFreq[key]].begin();

            // update the least frequecy counter --- IMPORTANT
            if(currFq==lfCnt && lfu[currFq].empty()) ++lfCnt;
        }
        // IF THE KEY DOES NOT EXIST
        else {
            // check for lfu capacity
            if(mp.size() == capacity) {
                // evict the lfu element
                int key_d = lfu[lfCnt].back().first;
                lfu[lfCnt].pop_back();
                mp.erase(key_d);
                keyFreq.erase(key_d);
            }

            // insert the new element into lfu
            lfCnt = keyFreq[key] = 1;
            lfu[keyFreq[key]].push_front({key, val});
            mp[key] = lfu[keyFreq[key]].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
