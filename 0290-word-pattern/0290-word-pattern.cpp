class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> charToWord;
        unordered_map<string,char> wordToChar;


        stringstream ss(s);
        vector<string> words;
        string temp;
        while(ss >> temp){
            words.push_back(temp);
        }

        if(pattern.size() != words.size()) return false;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            // if mapping exists and is already mapped to different one
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }
            
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }

            // create mapping (bijection)
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};
