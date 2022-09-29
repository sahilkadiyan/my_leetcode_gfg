class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;          //max priority queue
                                               //pair.first = difference , arr[i]-x & pair.second=index
    
    for(int i=0;i<k;i++){                      //First, push k elements into the priority_queue                    
        pq.push({abs(arr[i]-x),i});
    }
    
    for(int i=k;i<arr.size();i++){             //Then trvaerse from k to n (remaining elements) and if their 
        int diff=abs(arr[i]-x);                //difference is less than pq.top().first
        if(diff<pq.top().first){               //pop it and then push
            pq.pop();
            pq.push({diff,i});
        }
    }
    
    vector<int>v;
    while(!pq.empty()){                        //extracting elements from priority queue
        v.push_back(arr[pq.top().second]);
        pq.pop();
    }
    sort(v.begin(),v.end());
    return v; 
    }
};