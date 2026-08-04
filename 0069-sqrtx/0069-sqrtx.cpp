class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        for (int i = 1; i*i <= x; i++) {
            
            if (i*i <= x) ans = i;
            else break;
            if (i == 46340) break;
        }
        return ans;
    }
};