#include <bits/stdc++.h>
using namespace std;   
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here

        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int weight = it.first;
            int node = it.second;
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=weight;
            for(auto i : adj[node]){
                int adjNode = i.first;
                int edgweight = i.second;
                if(vis[adjNode]!=1){
                    pq.push({edgweight,adjNode});
                }
            }
        }
        return sum;
    }
};