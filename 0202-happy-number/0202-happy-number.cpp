class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n) == s.end()){
            s.insert(n);
            int temp = 0;
            while(n>0){
                temp += (n%10) * (n%10);
                n /= 10;
            }
            n = temp ;
            if(n==1) return true;
        }
        return false ;
    }
};