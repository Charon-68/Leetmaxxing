class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int temp = 1;
        while(temp <= n){
            temp = temp << 1;
        }
        return temp;
    }
};