class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> h(26,0);
        vector<bool> vis(26,false);
        for(int i=0 ; i<s.length() ; i++){
            h[s[i] - 'a']++;
        }
        string ans = "";
        for(int i=0 ; i<s.length() ; i++){
            h[s[i] - 'a']--;
            if(vis[s[i] - 'a']) continue;
            while(ans.size() && h[ans.back()-'a'] && ans.back() >= s[i]){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            } 

            ans += s[i];
            vis[s[i] - 'a'] = true;
            
        }
        return ans;
    }
};