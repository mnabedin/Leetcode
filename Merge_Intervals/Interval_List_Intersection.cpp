#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.empty() && !secondList.empty()) return {};
        if (secondList.empty() && !firstList.empty()) return {};
        vector<vector<int>> result;
        int first_ptr = 0, second_ptr = 0;       
        int first_size = firstList.size(), second_size = secondList.size();
        while (first_ptr < first_size && second_ptr < second_size) {
            vector<int> first_interval = firstList[first_ptr];
            vector<int> second_interval = secondList[second_ptr];
            if (first_interval[1] < second_interval[0]) {
                first_ptr++;
            } else if (second_interval[1] < first_interval[0]) {
                second_ptr++;
            } else {
                result.push_back({max(first_interval[0], second_interval[0]),
                        min(first_interval[1], second_interval[1])});
                first_interval[1] < second_interval[1] ? first_ptr++ : 
                    second_ptr++;
            }
        }
        return result;
    }
};

