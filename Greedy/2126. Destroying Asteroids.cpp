/*
not to much to explain simple to proof and think
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long val=mass;
        int i,n=asteroids.size();
        
        for(int i=0;i<n;i++)
        {
            if(val < asteroids[i])
            {
                return false;
            }
            
            val += asteroids[i];
        }
        
        return true;
    }
};