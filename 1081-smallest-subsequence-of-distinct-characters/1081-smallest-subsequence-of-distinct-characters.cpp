class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> vis(26,false);
        for(int i=0 ; i<s.length() ; i++){
            last[s[i] - 'a'] = i;
        }
        string ans = "";
        for(int i=0 ; i<s.length() ; i++){
            if(vis[s[i] - 'a']) continue;
            while(ans.size() && ans.back() >= s[i] && last[ans.back()-'a'] > i){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            } 
            ans += s[i];
            vis[s[i] - 'a'] = true;
        }
        return ans;
    }
};