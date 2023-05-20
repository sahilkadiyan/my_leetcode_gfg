class Solution {
public:

    double f(string &src,string &dest,map<string,vector<pair<string,double>>> &mpp){
        queue<pair<string,double>>q;
        set<string>st;
        q.push({src,(double)1});
        st.insert(src);
        while(!q.empty()){
            string temp = q.front().first;
            double val = q.front().second;
            if(temp == dest)return val;
            q.pop();
            for(int i = 0;i < mpp[temp].size();i++){
                string s1 = mpp[temp][i].first;
                double cost = mpp[temp][i].second;
                if(st.find(s1) == st.end()){
                    q.push({s1,cost*val});
                    st.insert(s1);
                }
            }
        }
        return (double)-1;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>mpp;
        for(int i = 0;i < equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            mpp[u].push_back({v,values[i]});
            mpp[v].push_back({u,(double)1/values[i]});
        }
        for(auto it : mpp){
            cout << it.first << ": ";
            for(int i = 0;i < mpp[it.first].size();i++){
                cout << "{"<< mpp[it.first][i].first << "," << mpp[it.first][i].second << "} ";
            }
            cout << endl;
        }
        vector<double>ans;
        for(int i = 0;i < queries.size();i++){
            string src = queries[i][0];
            string dest = queries[i][1];
            if(mpp.find(src) != mpp.end() && mpp.find(dest) != mpp.end()){
                ans.push_back(f(src,dest,mpp));
            }
            else{
                ans.push_back((double)-1);
            }
        }
        return ans;
    }
};