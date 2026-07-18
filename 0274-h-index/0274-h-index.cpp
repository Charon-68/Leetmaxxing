class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int ans = 0;
        for(int i=0 ; i<citations.size(); i++){
            ans = max(ans, min(i+1, citations[i]));
        }
        return ans;
    }
};