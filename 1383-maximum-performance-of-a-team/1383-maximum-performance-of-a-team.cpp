class Engineer {        
  public:          // Access specifier
    int speed,efficiency;      // Attributes
    Engineer(int speed, int efficiency) { // Constructor with parameters
      this->speed = speed;
      this->efficiency = efficiency;
    }
    
    bool operator < (Engineer const &obj) {
        if(this->efficiency == obj.efficiency)
            return this->speed > obj.speed;
        else 
           return this->efficiency > obj.efficiency;
    }
};


class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
      vector<Engineer>teams;
      long long ans = 0, speedSum = 0;
        
       for(int i=0;i<n;i++) {
           Engineer obj(speed[i],efficiency[i]);
           teams.push_back(obj);
       }
        
      sort(teams.begin(),teams.end());
      priority_queue<int,vector<int>,greater<int>>pq;
        
      for(Engineer engineer: teams) {
          
          while(pq.size()>=k) {
              speedSum -= pq.top();
              pq.pop();
          }
         pq.push(engineer.speed);
         speedSum += engineer.speed;
         ans = max (ans, 1LL * speedSum * engineer.efficiency);
      }  
       
        int mod = 1e9 + 7;
        return int(ans % mod);
    }
};