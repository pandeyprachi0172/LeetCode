class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;
            x = x / 10;

            if (ans > 214748364 || ans < -214748364) {
                return 0;
            }

            ans = ans * 10 + digit;
        }

        return ans;
    }
};
