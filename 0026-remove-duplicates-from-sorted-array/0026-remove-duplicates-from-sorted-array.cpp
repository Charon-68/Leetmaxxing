class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int l = 0;
        for(int r=0 ; r<n ; r++){
            while(r<n && nums[r] == nums[l]) r++;
            if(r==n) return l+1;
            nums[++l] = nums[r];
        }
        return l+1;
    }
};