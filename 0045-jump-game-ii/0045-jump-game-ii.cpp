class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int ans = 0;
        vector<int> dp(n, 1e7+1);
        dp[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            for (int j = 1; i+j <= min(n-1,i+nums[i]); j++) {
                dp[i] = min(dp[i], dp[i+j]);
            }
            dp[i]++;
        }
        return dp[0];
    }
};