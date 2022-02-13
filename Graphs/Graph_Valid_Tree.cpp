class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    vector<vector<int>> g;
    unordered_set<int> visit;
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        g = vector<vector<int>>(n);
        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        return dfs(0, -1) && n == visit.size();
    }
    
    bool dfs(int curr, int prev) {
        if(visit.find(curr) != visit.end()) return false;
        visit.insert(curr);
        for(int nei : g[curr]) {
            if(nei == prev) continue;
            if(!dfs(nei, curr)) return false;
        }
        return true;
    }
};