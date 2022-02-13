class Solution {
public:
    vector<vector<int>> g;
    vector<int> visit;
    vector<int> order;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g = vector<vector<int>>(numCourses);
        visit = vector<int>(numCourses, 0);
        for(auto e : prerequisites) g[e[1]].push_back(e[0]);
        for(int i = 0; i < numCourses; ++i) {
            if(topSort(i)) return vector<int>{};
        }
        reverse(order.begin(), order.end());
        return order;
    }
    
    bool topSort(int at) {
        if(visit[at] == -1) return true;
        if(visit[at] == 1) return false;
        visit[at] = -1;
        for(auto nei : g[at]) {
            if(topSort(nei)) return true;
        }
        visit[at] = 1;
        order.push_back(at);
        return false;
    }
    
};