class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> vec;

public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /* Using the map, we keep track of the indices (inside the array) where the elements are insertd, so that the 
    random access can easily be handled. So, we insert vec.size() as the value, and 'val' as the key */
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val]=vec.size();
        vec.push_back(val);
        return true;
    }
    

    /* While removing an element we need to rearrange the array, as any element from any index can be deleted, so 
    in order to delete the last element only (as it will cause lesser TC for array) we copy the value of the last 
    element to the position from where the current element will be deleted. And hence the tracking in 'mp' got 
    distured by the shifting so we need to update this one also.   */
    bool remove(int val) {
        if(mp.count(val)==0) return false;

        int curPos=mp[val], lastPos=vec.size()-1;
        vec[curPos]=vec[lastPos];  
        mp[vec[lastPos]]=curPos;

        vec.pop_back();
        mp.erase(val);
        return true;
    }

    
    int getRandom() {
        return vec[rand()%mp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */