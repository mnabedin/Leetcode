#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int window_start = 0, window_len = 0, n = fruits.size(), baskets = 2;
       unordered_map<int, int> map;
       for (int window_end = 0; window_end < n; window_end++) {
           const int fruit_at_end = fruits[window_end];
           map[fruit_at_end]++;
           while (map.size() > baskets) {
               const int fruit_at_start = fruits[window_start];
               map[fruit_at_start]--;
               if (map[fruit_at_start] == 0) map.erase(fruit_at_start);
               window_start++;
           }
           window_len = max(window_len, window_end - window_start + 1);
       }
       return window_len;
    }
};

