class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 == 1)
            return false;
        if (grid[0][0] == ')')
            return false;
        vector<bitset<201>> dp(n);
        dp[0][1] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    continue;
                bitset<201> possible;
                if (i > 0)
                    possible |= dp[j];
                if (j > 0)
                    possible |= dp[j - 1];
                if (grid[i][j] == '(') {
                    dp[j] = (possible << 1);
                } else {
                    dp[j] = (possible >> 1);
                }
                int remaining = (m - 1 - i) + (n - 1 - j);
                for (int balance = remaining + 1; balance <= 200; ++balance)
                    dp[j][balance] = 0;
            }
        }
        return dp[n - 1][0];
    }
};
