class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int , unordered_set<int>> hashMap;    // Initializing required hashmap.
        hashMap[stones[0] + 1] = {1};       // Viable Jump Sizes to reach 2nd stone.
        for(int i = 1 ; i < stones.size() ; ++i){       // Traversing all positions
            int position = stones[i];                   // Current Position
            for(auto it : hashMap[position]){           // Traversing all viable jump sizes that can be used from current position.
                hashMap[position + it].insert(it);      // Populating the sets of positions that can be reached from current position with a viable jump size.
                hashMap[position + it + 1].insert(it + 1);
                hashMap[position + it - 1].insert(it - 1);
            }
        }
        return hashMap[stones.back()].size() != 0;     // Checking the set size of last stone.
    }
};