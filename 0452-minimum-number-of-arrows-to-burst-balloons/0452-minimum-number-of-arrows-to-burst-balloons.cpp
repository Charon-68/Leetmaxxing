class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    if(n==1) return 1;
    sort(points.begin(), points.end(),[](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });
    int ans = 0;
    int i = 0;
    while(i<n){
        int end = points[i][1];
        ans++;
        while(i<n && points[i][0] <= end) i++;
    }
    return ans;
}
};



