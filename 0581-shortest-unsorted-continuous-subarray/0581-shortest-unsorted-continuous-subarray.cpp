class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int least = 1e6 + 1;
        int end = -1;
        int greatest = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(nums[n-1-i] > least) start = n-1-i;
            least = min(least, nums[n-1-i]);

            if(nums[i] < greatest) end = i;
            greatest = max(greatest, nums[i]);
        }
        return end - start + 1;
    }
};