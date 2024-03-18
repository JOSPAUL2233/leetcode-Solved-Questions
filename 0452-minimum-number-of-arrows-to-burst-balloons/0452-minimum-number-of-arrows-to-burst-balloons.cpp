class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        auto cmp = [](vector<int>& a,vector<int>& b){
            
            return a[1]<b[1];
            
        };
        
        sort(points.begin(),points.end(),cmp);
        
        int end = points[0][1];
        int count = 1;
        
        for(auto it : points){
            
            if(it[0]>end){
                count++;
                end = it[1];
            }
            
        }
        
        return count;
        
    }
};