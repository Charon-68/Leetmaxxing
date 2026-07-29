class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int n = nums.size();
        
        vector<string> ans;
        if (n == 0) return ans;
        if (n == 1) {ans.push_back(to_string(nums[0])); return ans;}
        int st = 0, end = 1;
        while (st < n && end < n) {
            if ((long long)(nums[end]) - (long long)(nums[st]) == end-st) end++;
            else if (end - st == 1) {
                ans.push_back(to_string(nums[st]));
                st = end;
                end = st+1;
            }
            else {
                ans.push_back(to_string(nums[st]) + "->"+ to_string(nums[end-1]));
                st = end;
                end = st+1;
            }
        }
        if (end - st == 1) ans.push_back(to_string(nums[st]));
        else ans.push_back(to_string(nums[st]) + "->"+ to_string(nums[end-1]));
        return ans;
    }
};