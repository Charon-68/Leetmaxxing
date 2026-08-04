class Solution {
public:
    int trailingZeroes(int n) {
        int two = 0;
        int five = 0;
        for(int i=2 ; i<=n ; i++){
            int temp = i;
            while(i%2 == 0){
                two++;
                i /= 2;
            }
            while(i%5 == 0){
                five++;
                i /= 5;
            }
            i = temp;
        }

        return min(two,five);
    }
};