class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        //get the min value from right and max value from left
        int rightLast = INT_MAX;
        int leftLast = INT_MIN;
        
        for(int i = 0;i<right.size();i++){
            
            rightLast = min(rightLast,right[i]);
            
        }
        
        for(int i = 0;i<left.size();i++){
            
            leftLast = max(leftLast,left[i]);
            
        }
        
        //teke the greater distance from the edge
        
        int greater = leftLast > (n-rightLast) ? leftLast : (n-rightLast);
        
        return greater;
        
    }
};