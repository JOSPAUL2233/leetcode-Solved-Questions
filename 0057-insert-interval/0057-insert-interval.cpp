class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        
        int start = newInterval[0];
        int end = newInterval[1];
        int n = intervals.size();
        
        int i = 0;

        //push back all the intervals which are not overlapping
        while(i < n && intervals[i][1] < start){
            
            ans.push_back(intervals[i]);
            i++;
            
        } 

        //merge the intervals which are overlapping
        vector<int> mergedInterval = {start, end};
        
        while(i < n && intervals[i][0] <= end){
            
            mergedInterval[0] = min(mergedInterval[0], intervals[i][0]);
            mergedInterval[1] = max(mergedInterval[1], intervals[i][1]);
            
            i++;
            
        }
        
        ans.push_back(mergedInterval);

        //push back all ther remaining intervals which aren't overlapping
        
        while(i < n){
            
            ans.push_back(intervals[i]);
            i++;
        
        }

        return ans;        
    }
};