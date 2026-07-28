class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> s;
        for(int x : nums){
            s.insert(x);
        }

        int ct = 1;
        int ans = 1;

        for(int a : s){
            if(s.find(a-1) != s.end()) ct++;
            else ct = 1;
            ans = max(ans, ct);
        }
        return ans;
    }
};