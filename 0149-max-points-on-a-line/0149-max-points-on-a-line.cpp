class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int ans = 2;

        for(int i=0 ; i<n ; i++){
            map<pair<int,int>,int> m;
            int temp = 0;
            for(int j=0 ; j<n ; j++){
                if(i==j) continue;
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                int g = gcd(dy, dx);
                dy /= g;
                dx /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                m[{dy, dx}]++;
                temp = max(temp, m[{dy, dx}]);
            }
            ans = max(ans, temp+1);
        }
        return ans;
    }
};