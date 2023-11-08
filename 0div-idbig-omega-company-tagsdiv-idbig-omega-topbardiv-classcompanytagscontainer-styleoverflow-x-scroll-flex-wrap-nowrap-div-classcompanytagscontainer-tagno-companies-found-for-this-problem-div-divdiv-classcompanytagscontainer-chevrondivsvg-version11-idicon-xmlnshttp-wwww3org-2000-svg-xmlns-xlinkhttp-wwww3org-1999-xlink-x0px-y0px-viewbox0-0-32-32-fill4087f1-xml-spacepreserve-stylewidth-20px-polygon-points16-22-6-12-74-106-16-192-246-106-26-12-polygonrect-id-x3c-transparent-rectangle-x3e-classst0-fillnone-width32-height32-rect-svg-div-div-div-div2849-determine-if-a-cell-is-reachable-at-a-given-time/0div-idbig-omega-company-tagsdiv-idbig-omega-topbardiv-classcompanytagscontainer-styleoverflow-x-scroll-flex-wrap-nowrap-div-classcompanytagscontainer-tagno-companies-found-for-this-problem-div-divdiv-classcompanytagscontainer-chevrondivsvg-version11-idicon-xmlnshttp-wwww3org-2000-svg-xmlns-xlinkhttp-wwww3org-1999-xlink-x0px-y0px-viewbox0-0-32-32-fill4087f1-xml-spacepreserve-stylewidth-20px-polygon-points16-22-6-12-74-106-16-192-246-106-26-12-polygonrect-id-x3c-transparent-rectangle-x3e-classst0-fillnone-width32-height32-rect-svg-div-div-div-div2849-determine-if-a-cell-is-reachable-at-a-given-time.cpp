class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        //edge case comes if the points are same
        if(sx == fx && sy == fy){
            
            if(t == 1)//edge case
                return false;
            else
                return true;
            
        }
        
        int xDiff = abs(sx-fx);
        int yDiff = abs(sy-fy);
                
        int diagonal = min(xDiff,yDiff);

        int remaining = max(xDiff,yDiff) - min(xDiff,yDiff);
        
        int leastTime = diagonal + remaining;
                
        return (leastTime <= t);
        
    }
};