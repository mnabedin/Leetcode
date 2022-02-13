class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), offset = 0, i = 0, j = 0;
        string direction = "right";
        vector<int> res(m * n);
        for(int ii = 0; ii < m * n; ii++) {
            res[ii] = matrix[i][j];
            if(direction == "right") {
                if(j == n - offset - 1) {
                    direction = "down";
                    i++;
                } else {
                    j++;
                }
            }
            else if(direction == "down") {
                if(i == m - offset - 1) {
                    direction = "left";
                    j--;
                } else {
                    i++;
                }
            }
            else if(direction == "left") {
                if(j == offset) {
                    direction = "up";
                    i--;
                } else {
                    j--;
                }
            } else {
                if(i == offset + 1) {
                    direction = "right";
                    offset++;
                    j++;
                } else {
                    i--;
                }
            }
        }
        return res;
    }
};