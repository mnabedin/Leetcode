class Solution {
public:
    int f(const vector<int>& v, int x) {
        int left = 0, right = v.size() - 1;
        int amount_so_far = v.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] >= x) {
                amount_so_far = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return amount_so_far;
    }
    
    
    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) {
        vector<vector<int>> umap(101);
        for (auto& r : rect) {
            umap[r[1]].push_back(r[0]);
        }
        for (int i = 0; i < 101; i++) {
            sort(umap[i].begin(), umap[i].end());
        }
        
        vector<int> res;
        for(auto& p : points) {
            int count = 0;
            for (int y = p[1]; y < 101; y++) {
                if (umap[y].size()) {
                    count += umap[y].size() - f(umap[y], p[0]);
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
