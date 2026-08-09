class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        
        for(int i=0 ; i<n ; i++){
            bool destroyed = false;
            
            while(!ans.empty() && ans.back() > 0 && asteroids[i] < 0) {
                if(ans.back() < abs(asteroids[i])) {
                    ans.pop_back();
                    continue;
                } else if(ans.back() == abs(asteroids[i])) {
                    ans.pop_back();
                }
                
                destroyed = true;
                break;
            }
            
            if(!destroyed) {
                ans.push_back(asteroids[i]);
            }
        }
        
        return ans;
    }
};