class Solution {
public:
    int mySqrt(int x) {
        int ans;
        for (int i = 1; i <= x/2; i++) {
            if (i == 46341) break;
            if (i*i <= x) ans = i;
            else break;
        }
        return ans;
    }
};