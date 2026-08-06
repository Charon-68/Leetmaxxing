class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans1 = INT_MIN;
        int sum = 0;
        int total_sum = 0;
        for(int i=0 ; i<n ; i++){
            total_sum += nums[i];
            sum += nums[i];
            ans1 = max(ans1, sum);
            if(sum < 0) sum = 0;
        }
        int ans3 = INT_MIN;
        sum = 0;
        int ans2 = INT_MAX;
        for(int i=0 ; i<n ; i++){
            ans3 = max(ans3, nums[i]);
            sum += nums[i];
            ans2 = min(ans2, sum);
            if(sum > 0) sum = 0;
        }
        if(total_sum - ans2 == 0) return max(ans1, ans3);
        return max(ans1, total_sum - ans2);
    }
};



