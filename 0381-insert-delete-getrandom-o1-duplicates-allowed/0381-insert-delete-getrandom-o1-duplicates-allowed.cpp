class RandomizedCollection {
    
    private:
    vector<int> lst;
    unordered_map<int,unordered_set<int>> idx;
    default_random_engine rand;
public:
    RandomizedCollection() :rand(random_device{}()) {
        
    }
    
    bool insert(int val) {
        if(!idx.count(val)) idx[val]=unordered_set<int>();
        idx[val].insert(lst.size());
        
        lst.push_back(val);
        
        return idx[val].size()==1;
        
    }
    
    bool remove(int val) {
        if(!idx.count(val) || idx[val].size()==0) return false;
        int removeIdx= *idx[val].begin();
        idx[val].erase(removeIdx);
        int last=lst.back();
        lst[removeIdx]=last;
        idx[last].insert(removeIdx);
        idx[last].erase(lst.size()-1);
        
        lst.pop_back();
        return true;
        
    }
    
    int getRandom() {
        uniform_int_distribution<int> dist(0,lst.size()-1);
        return lst[dist(rand)];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */