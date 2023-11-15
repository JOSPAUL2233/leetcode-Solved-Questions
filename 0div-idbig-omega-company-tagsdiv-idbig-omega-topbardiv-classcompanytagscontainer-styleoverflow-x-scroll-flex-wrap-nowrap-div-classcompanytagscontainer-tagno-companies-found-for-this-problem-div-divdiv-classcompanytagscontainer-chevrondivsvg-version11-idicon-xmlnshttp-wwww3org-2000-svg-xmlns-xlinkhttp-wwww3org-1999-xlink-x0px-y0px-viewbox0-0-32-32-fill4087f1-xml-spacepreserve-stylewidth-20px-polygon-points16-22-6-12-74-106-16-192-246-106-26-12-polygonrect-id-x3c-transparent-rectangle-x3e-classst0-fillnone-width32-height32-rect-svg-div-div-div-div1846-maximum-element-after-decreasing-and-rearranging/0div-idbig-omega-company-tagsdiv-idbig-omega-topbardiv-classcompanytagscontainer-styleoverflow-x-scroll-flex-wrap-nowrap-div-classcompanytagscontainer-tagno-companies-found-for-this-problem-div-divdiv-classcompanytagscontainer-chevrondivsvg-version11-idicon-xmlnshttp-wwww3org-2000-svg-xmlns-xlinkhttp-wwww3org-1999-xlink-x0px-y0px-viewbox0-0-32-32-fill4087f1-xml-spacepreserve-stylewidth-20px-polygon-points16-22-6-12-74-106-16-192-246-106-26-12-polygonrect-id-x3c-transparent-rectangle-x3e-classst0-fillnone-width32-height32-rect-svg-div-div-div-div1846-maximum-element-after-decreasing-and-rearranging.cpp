class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int prev = 0;
        sort(arr.begin(),arr.end());
        
        for(int i = 0;i<arr.size();i++){
            
            prev++;
            prev = min(prev,arr[i]);
                        
        }
        
        return prev;
        
    }
};