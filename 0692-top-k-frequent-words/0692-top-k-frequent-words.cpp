class Solution {

   struct Comparator {
       bool operator() (const pair<int,string> &ff, pair<int,string> &ss)  {
       if (ff.first != ss.first)
          return ff.first > ss.first;
       else
          return ff.second < ss.second; 
        } 
   };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>res;
        unordered_map<string,int>freq;
        for( string word: words) {
            freq[word]++;
        }

        priority_queue<pair<int,string>, vector<pair<int, string>>, Comparator>pq;
        for( auto const & [key,val]: freq) {
            pq.push({val,key});
            if (pq.size() > k)
              pq.pop();
        }

        while(!pq.empty() && res.size() != k) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};