
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);

                // Avoid product overflow
                if (prod > 1e18 / nums[j]) {
                    break;
                }

                prod *= nums[j];

                l = l / gcd(l, (long long)nums[j]) * nums[j];

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
