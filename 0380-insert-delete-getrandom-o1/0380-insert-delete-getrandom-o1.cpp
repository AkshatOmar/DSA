class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mp;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            v.push_back(val);
            mp[val] = v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) {
            return false;
        }
        int idx = mp[val];
        int last = v.back();
        mp[last] = idx;
        v[idx] = last;
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */