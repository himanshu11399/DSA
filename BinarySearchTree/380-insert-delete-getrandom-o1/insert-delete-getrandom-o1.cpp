class RandomizedSet {
public:
    // It will Store <value,index>
    unordered_map<int, int> mpp;
    vector<int> pos;
    int randomvalue = 0;
    RandomizedSet() {}

    bool insert(int val) {
        if (mpp.find(val) == mpp.end()) {
            pos.push_back(val);
            int idx = pos.size() - 1;
            mpp[val] = idx;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (mpp.find(val) != mpp.end()) {
            int currIdx = mpp[val];
            int lastIdx = pos.size() - 1;
            swap(pos[currIdx], pos[lastIdx]);
            mpp[pos[currIdx]] = currIdx;
            mpp.erase(pos[lastIdx]);
            pos.pop_back();
            return true;
        }
        return false;
    }

    int getRandom() {
        int randomIdx = rand() % pos.size();
        
        return pos[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */