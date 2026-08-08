class Solution {
    int hours(int speed, vector<int>& p){
        int ans = 0;
        for(int i=0 ; i<p.size() ; i++){
            ans += p[i]/speed;
            if(p[i] % speed) ans++;
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l<r){
            int mid = l + (r-l)/2;
            if(hours(mid, piles) > h) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};






// int sum = accumulate(piles.being(), piles.end(), 0);