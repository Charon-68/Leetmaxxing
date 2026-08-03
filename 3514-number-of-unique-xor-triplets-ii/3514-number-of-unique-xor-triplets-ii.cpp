class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> two(2048,false);
        
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                two[nums[i] ^ nums[j]] = true;
            }
        }

        int ans = 0;
        vector<bool> three(2048,false);

        for(int i=0 ; i<2048 ; i++){
            if(!two[i]) continue;
            for(int j=0 ; j<n ; j++){
                if(!three[i ^ nums[j]]){
                    three[i ^ nums[j]] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};