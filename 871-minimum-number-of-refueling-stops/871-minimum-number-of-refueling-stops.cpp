class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        	int ans = 0;
		priority_queue<int> pq;
		
		int maxFule = startFuel;
		
		for(auto station : stations) {
			int nextStation = station[0];
			int nextFuleValue = station[1];
			
			while(maxFule < nextStation) {
                if(pq.empty()) {
                    ans=-1;
                    break;
                }
				maxFule += pq.top();
                pq.pop();
				ans++;
			}
            if(ans == -1) break;
            
            pq.push(nextFuleValue);
			
		}
		
		while(maxFule < target) {
			if(pq.empty()) {
				ans = -1;
				break;
			}
			maxFule += pq.top();
			ans++;
			pq.pop();
		}
		
		return ans;
	}
    
};