class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        for (int r=1; r<n; r++) {
            if (nums[r] != nums[l]) {
                nums[++l] = nums[r];
            }
        }
        return l+1;
    }
};