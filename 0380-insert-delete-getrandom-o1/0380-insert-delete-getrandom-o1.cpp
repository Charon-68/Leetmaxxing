class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> m;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        nums.push_back(val);
        m[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int idx = m[val];
        int last = nums.back();
        nums[idx] = last;
        nums.pop_back();
        m[last] = idx;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */