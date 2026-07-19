class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        int m = (numRows-1)*2;
        if (numRows == 1) return s;
        string ans;
        for (int a = 0; a <= m/2; a++) {
            for (int i = 0; i < n+m; i+=m) {
                if (a != m/2 && i-a >= 0 && i-a < n) ans += s[i-a];
                if (a != 0 && i+a < n) ans += s[i+a];
            }
        }
        return ans;
    }
};