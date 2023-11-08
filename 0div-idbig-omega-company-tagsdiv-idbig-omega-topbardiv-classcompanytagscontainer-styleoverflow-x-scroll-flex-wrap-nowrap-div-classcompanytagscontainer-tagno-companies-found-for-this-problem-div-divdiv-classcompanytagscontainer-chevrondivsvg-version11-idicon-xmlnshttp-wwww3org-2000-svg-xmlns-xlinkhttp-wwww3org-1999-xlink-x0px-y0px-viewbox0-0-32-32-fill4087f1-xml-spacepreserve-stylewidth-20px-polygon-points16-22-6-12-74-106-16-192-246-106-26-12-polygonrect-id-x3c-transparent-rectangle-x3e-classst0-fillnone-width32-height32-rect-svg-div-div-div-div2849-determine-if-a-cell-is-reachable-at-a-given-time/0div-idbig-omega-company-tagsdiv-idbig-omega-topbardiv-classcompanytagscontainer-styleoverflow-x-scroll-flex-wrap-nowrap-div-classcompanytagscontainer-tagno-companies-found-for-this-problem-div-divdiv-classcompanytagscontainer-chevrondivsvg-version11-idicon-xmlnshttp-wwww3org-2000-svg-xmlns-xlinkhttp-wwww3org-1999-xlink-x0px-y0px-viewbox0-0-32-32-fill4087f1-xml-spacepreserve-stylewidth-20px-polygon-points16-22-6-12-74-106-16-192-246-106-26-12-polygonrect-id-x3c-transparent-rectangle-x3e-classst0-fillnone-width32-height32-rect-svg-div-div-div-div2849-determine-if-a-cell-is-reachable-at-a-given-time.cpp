class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        //edge case comes if the points are same
        if(sx == fx && sy == fy){
            
            if(t == 1)//edge case, t goes out and never comes back
                return false;
            else
                return true;
            
        }
        
        //get the total distance that should be travelled in x and y direction
        int xDiff = abs(sx-fx);
        int yDiff = abs(sy-fy);
                
        //get the diagonal distance that can be travelled
        int diagonal = min(xDiff,yDiff);

        //get the distance that is left after travelling through diagonal
        int remaining = abs(xDiff - yDiff);
        
        //this gives the leastTime that t should take to reach to the final
        int leastTime = diagonal + remaining;
                
        //if is always true if t is greater or equal to leastTime since it can roam
        //around if the t is more.
        return (leastTime <= t);
        
    }
};