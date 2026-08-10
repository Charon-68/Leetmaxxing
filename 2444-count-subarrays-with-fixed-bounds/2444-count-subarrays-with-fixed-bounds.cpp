class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int a = -1, b = -1;
        int l = 0;
        long long int ans = 0;
        for(int r=0 ; r<n ; r++){
            if(nums[r] > maxK || nums[r] < minK){
                a = -1; b = -1; if(r< n-1) l = r+1;
            }
            if(nums[r] == minK) a = r;
            if(nums[r] == maxK) b = r;
            if(a >= l && a <= r && b >= l && b <= r){
                ans = ans + min(a,b)-l+1;
            }
        }
        return ans;
    }
};