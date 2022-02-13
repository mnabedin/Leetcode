class Solution {
public:
    int m, n;
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> ans;
    vector<int> dr, dc;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size() == 0) return ans;
        m = heights.size(), n = heights[0].size();
        atlantic = pacific = vector<vector<bool>> (m, vector<bool> (n, false));
        dr = {1, -1, 0, 0};
        dc = {0, 0, 1, -1};
        
        for(int i = 0; i < m; i++) {
        	dfs(heights, i, 0, heights[i][0], pacific);
        	dfs(heights, i, n - 1, heights[i][n - 1], atlantic);
        }
        
        for(int j = 0; j < n; j++) {
        	dfs(heights, 0, j, heights[0][j], pacific);
        	dfs(heights, m - 1, j, heights[m - 1][j], atlantic);
        }
        
        return ans;
    }
    
    
    void dfs(const vector<vector<int>>& heights, int r, int c, int prev, vector<vector<bool>>& visit) {
        if(r < 0 || r >= m || c < 0 || c >= n || heights[r][c] < prev || visit[r][c]) 
            return;
        visit[r][c] = true;
        
        if(pacific[r][c] && atlantic[r][c]) ans.push_back(vector<int>{r, c});
        for(int x = 0; x < 4; x++) {
            int rr = r + dr[x];
            int cc = c + dc[x];
            dfs(heights, rr, cc, heights[r][c] ,visit);
        }
    }
};