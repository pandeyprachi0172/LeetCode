class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int start = 0; start < n; ++start) {
            unordered_set<int> seen;
            for (int end = start; end < n; ++end) {
                seen.insert(nums[end]);
                int distinct = seen.size();
                total += distinct * distinct;
            }
        }
        return total;
    }
};