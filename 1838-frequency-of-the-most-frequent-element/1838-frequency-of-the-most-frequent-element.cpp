class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int ans = 0;
        long long int ct = 0;
        for(int r=0 ; r<n ; r++){
            if(r>0 && nums[r] == nums[r-1]){
                ans = max(ans, r-l+1);
                continue;
            }
            if(r>0) ct += 1LL * (r-l) * (nums[r] - nums[r-1]);
            while(ct > k){
                ct -= nums[r] - nums[l];
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};