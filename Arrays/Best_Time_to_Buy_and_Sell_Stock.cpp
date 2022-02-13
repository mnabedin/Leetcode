class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0, min_price = INT_MAX;
        for(int i = 0; i < n; ++i) {
            min_price = min(min_price, prices[i]);
            res = max(res, prices[i] - min_price);
        }
        return res;
    }
};
