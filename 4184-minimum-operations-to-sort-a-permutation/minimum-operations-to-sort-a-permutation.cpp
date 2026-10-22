class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](const vector<int>& a) -> int {
            int k = find(a.begin(), a.end(), 0) - a.begin();

            for (int i = 0; i < n; i++) {
                if (a[(k + i) % n] != i)
                    return -1;
            }

            return k;
        };

        int k = check(nums);

        if (k != -1) {
            if (k == 0) return 0;
            return min(k, n - k + 2);
        }

        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());
        k = check(rev);
        if (k != -1) {
            return min(k + 1, n - k + 1);
        }
        return -1;
    }
};