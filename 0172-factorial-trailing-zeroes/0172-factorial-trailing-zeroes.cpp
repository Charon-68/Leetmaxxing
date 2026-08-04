class Solution {
public:
    int trailingZeroes(int n) {
        int two = 0;
        int five = 0;
        int temp;
        for(int i=2 ; i<=n ; i++){
            temp = i;
            while(i%2 == 0 && i%5 == 0){
                two++;
                five++;
                i /= 2;
                i /= 5;
            }
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