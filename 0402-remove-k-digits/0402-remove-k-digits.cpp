class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        int ct = 0;
        for(int i=0 ; i<n ; i++){
            int curr = num[i] - '0';
            while(!st.empty() && ct < k && st.top() > curr){
                st.pop();
                ct++;
            }
            st.push(curr);
        }
        while(ct < k){
            st.pop();
            ct++;
        } 
        string ans;
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int l = 0;
        while(ans[l] == '0') l++;
        ans = ans.substr(l);
        if(ans == "") return "0";
        return ans;
    }
};