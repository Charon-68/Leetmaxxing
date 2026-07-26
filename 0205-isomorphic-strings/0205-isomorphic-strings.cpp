class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<vector<int>> a(128);
        for(int i=0 ; i<s.length() ; i++){
            a[s[i]].push_back(i);
        }
        sort(a.begin(), a.end());

        vector<vector<int>> b(128);
        for(int i=0 ; i<t.length() ; i++){
            b[t[i]].push_back(i);
        }
        sort(b.begin(), b.end());

        return a == b ? true : false;
    }
};