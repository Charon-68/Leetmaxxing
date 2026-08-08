class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i] <= 0) nums[i] = 0;
            else if(nums[i] == i+1) continue;
            else{
                int temp = 0;
                swap(temp, nums[i]);
                while(temp > 0 && temp <= n && temp != nums[temp-1]){
                    swap(nums[temp-1], temp);
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};