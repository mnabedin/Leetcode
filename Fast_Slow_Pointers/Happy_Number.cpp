class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            slow = find_square_sum(slow);
            fast = find_square_sum(find_square_sum(fast));
        } while (fast != slow);
        return slow == 1;
    }

    int find_square_sum(int n) {
        int sum = 0, digit;
        while (n > 0) {
            digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

