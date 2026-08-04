class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num : nums){
            m[num]++;
            if(m[num] == 3) m.erase(num);
        }
        // auto * it = m.begin();
        // int ans = *it.first;
        return m.begin()->first;
    }
};