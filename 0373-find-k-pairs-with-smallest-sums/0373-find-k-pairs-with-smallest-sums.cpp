class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        set<pair<int,int>> s;
        s.insert({0,0});

        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({nums1[0]+nums2[0],0,0});

        while(k--){
            auto curr = pq.top();
            pq.pop();
            
            ans.push_back({nums1[curr[1]], nums2[curr[2]]});

            if(curr[1]+1 < nums1.size() && s.find({curr[1]+1,curr[2]}) == s.end()){
                pq.push({nums1[curr[1]+1] + nums2[curr[2]],curr[1]+1, curr[2]});
                s.insert({curr[1]+1,curr[2]});
            }
            if(curr[2]+1 < nums2.size() && s.find({curr[1],curr[2]+1}) == s.end()){
                pq.push({nums1[curr[1]] + nums2[curr[2]+1],curr[1], curr[2]+1});
                s.insert({curr[1],curr[2]+1});
            }
        }
        return ans;
    }
};

