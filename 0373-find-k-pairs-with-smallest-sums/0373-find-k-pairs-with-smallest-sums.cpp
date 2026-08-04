class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k--){
            auto curr = pq.top();
            pq.pop();
            
            ans.push_back({nums1[curr[1]], nums2[curr[2]]});

            if(curr[2] + 1 < nums2.size()){
                pq.push({nums1[curr[1]] + nums2[curr[2] + 1], curr[1], curr[2] + 1});
            }
        }
        return ans;
    }
};