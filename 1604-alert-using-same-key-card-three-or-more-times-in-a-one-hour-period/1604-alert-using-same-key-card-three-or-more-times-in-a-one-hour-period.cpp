class Solution {
    bool func(string name, unordered_map<string, vector<int>>& m){
        sort(m[name].begin(), m[name].end());
        int n = m[name].size();
        int l = 0;
        for(int r=0 ; r<n ; r++){
            while(m[name][r] - m[name][l] > 100) l++;
            if(r<n && r - l >= 2) return true;
        }
        return false;
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        for(int i=0 ; i<keyName.size() ; i++){
            m[keyName[i]].push_back(stoi(keyTime[i].substr(0,2))*100 + stoi(keyTime[i].substr(3)));
        }
        vector<string> ans;
        for(auto person : m){
            if(func(person.first,m)) ans.push_back(person.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};