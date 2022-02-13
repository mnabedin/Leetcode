class Solution {
public:
    vector<vector<int>> g;
    vector<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses);
        visited = vector<int>(numCourses, 0);
        for(auto e : prerequisites) g[e[1]].push_back(e[0]);
        for(int i = 0; i < numCourses; i++) {
            if(topSort(i)) return false;
        }
        return true;
    }
    
    bool topSort(int at) {
        if(visited[at] == -1) return true;
        if(visited[at] == 1) return false;
        visited[at] = -1;
        for(auto nei : g[at]) {
            if(topSort(nei)) return true;
        }
        visited[at] = 1;
        return false;
    }
    
};