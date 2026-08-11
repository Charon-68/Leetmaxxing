class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) ==  dict.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            auto [s,level] = q.front();
            q.pop();
            if(s == endWord) return level;
            for(int i=0 ; i<s.length() ; i++){
                char temp = s[i];
                for(int j=0 ; j<26 ; j++){
                    s[i] = 'a' + j;
                    if(dict.find(s) != dict.end()){
                        q.push({s, level+1});
                        dict.erase(s);
                    }
                }
                s[i] = temp;
            }
        }
        return 0;
    }
};