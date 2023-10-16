//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> vis(V,0);
        // (wt,node)
        
        //initially push 0 as the weight and the node since it is a 0 based indexing that's the reason 
        
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node]==1) continue; //if it is already visited then there is no need to add this thing to the visited array 
            //if it is not visited then mark it as visited only when we are adding this thing to the final MST
            vis[node]=1;
            sum+=wt;
            
            //this is for the adjacent nodes and all 
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edW=it[1];
                if(!vis[adjNode]){
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends