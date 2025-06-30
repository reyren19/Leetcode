class DisjointSet {
    vector<int> size, parent;

public:
    // constructor that declares the parent and the size array
    DisjointSet(int n) {
        // n+1 to account for 1 based indexing graphs
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node) {
        // if node is parent of itself, return it as it is
        if (node == parent[node]) {
            return parent[node];
        }
        // recursion to find parent + path compression
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v) {
            // nodes already in same graph
            return;
        }
        if (size[ulp_u] > size[ulp_v]) {
            // attach node and increase size by the size of ult parent
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        } else {
            // either the case that v > u or they are both the same, just attach
            // u to v
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // taking mail as key as it is easier to track it later
        unordered_map<string, int> mapMailNode;
        int n = accounts.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            // start from 1 as the name is the first element in the vector
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    auto it = mapMailNode.find(mail);
                    int node = it->second;
                    ds.unionBySize(node, i);
                }
            }
        }
        vector<vector<string>> ans(n);
        vector<vector<string>> res;
        for(int i=0; i<n; i++){
            string name = accounts[i][0];
            ans[i].push_back(name);
        }
        for(auto mp: mapMailNode){
            int node = mp.second;
            int ulPar = ds.findUltimateParent(node);
            ans[ulPar].push_back(mp.first);
        }
        for(auto &it: ans){
            if(it.size()>1){
                sort(it.begin()+1, it.end());
                res.push_back(it);
            }
        }
        return res;
    }
};