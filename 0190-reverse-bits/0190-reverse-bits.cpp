class Solution {
public:
    int reverseBits(int n) {
        vector<int> bits(32,0);
        int i = 0;
        while(n){
            bits[i] = n&1;
            n /= 2;
            i++;
        }
        int ans = 0;
        for(int i=1 ; i<32 ; i++){
            if(bits[i]) ans += 1 << 31-i;

        }
        return ans;
    }
};