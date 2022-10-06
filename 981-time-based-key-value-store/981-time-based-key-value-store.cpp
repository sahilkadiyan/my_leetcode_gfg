class TimeMap {
public:
    unordered_map<string, map<int, string>> maps;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        maps[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!maps.count(key)) {
            return "";
        }
        auto it = maps[key].upper_bound(timestamp);
        if (it != maps[key].begin()) {
            return (--it)->second;
        } else {
            return "";
        }
    }
};