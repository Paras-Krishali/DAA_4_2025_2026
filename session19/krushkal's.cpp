#include <bits/stdc++.h>    
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        DisjointSet ds(V);
        int mstWeight = 0;
        int edgeCount = 0;

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(ds.findPar(u) != ds.findPar(v)) {
                mstWeight += w;
                ds.unionBySize(u, v);
                edgeCount++;

                if(edgeCount == V - 1)
                    break;
            }
        }

        return mstWeight;
    }
};