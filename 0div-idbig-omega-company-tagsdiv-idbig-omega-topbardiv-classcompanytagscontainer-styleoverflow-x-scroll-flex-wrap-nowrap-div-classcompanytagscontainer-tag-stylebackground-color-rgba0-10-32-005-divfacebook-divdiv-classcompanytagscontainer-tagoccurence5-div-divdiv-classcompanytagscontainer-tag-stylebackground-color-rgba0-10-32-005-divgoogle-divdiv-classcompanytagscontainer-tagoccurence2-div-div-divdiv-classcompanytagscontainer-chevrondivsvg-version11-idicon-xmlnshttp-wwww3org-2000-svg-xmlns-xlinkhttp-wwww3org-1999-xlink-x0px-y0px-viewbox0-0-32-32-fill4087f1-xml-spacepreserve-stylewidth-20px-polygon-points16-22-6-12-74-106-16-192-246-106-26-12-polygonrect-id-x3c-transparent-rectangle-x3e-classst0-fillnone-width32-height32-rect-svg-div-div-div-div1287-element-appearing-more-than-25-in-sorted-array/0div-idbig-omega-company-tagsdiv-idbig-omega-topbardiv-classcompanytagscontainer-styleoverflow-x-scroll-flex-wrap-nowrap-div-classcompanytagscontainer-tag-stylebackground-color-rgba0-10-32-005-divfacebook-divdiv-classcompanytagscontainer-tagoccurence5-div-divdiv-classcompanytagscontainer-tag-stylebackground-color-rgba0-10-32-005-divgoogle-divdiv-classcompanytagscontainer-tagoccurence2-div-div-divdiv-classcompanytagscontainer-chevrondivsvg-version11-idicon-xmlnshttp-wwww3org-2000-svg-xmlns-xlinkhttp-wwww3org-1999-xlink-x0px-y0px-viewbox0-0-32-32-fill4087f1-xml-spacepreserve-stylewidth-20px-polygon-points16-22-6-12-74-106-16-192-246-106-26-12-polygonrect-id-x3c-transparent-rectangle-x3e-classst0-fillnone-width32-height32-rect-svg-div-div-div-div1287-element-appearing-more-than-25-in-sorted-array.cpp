class Solution {
public:
    
    int findLen(vector<int> arr,int target){
        
        int start = 0;
        int end = arr.size()-1;
        
        int firstOccurance = -1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                
                firstOccurance = mid;
                
            }
            
            if(arr[mid] >= target)
                end = mid-1;
            else
                start = mid+1;

        }
        
        int lastOccurance = -1;
        start = 0;
        end = arr.size()-1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                
                lastOccurance = mid;
                
            }
            
            if(arr[mid] > target)
                end = mid-1;
            else
                start = mid+1;

        }
        
        return lastOccurance - firstOccurance + 1;
        
    }
    
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> indices = {n/4,n/2,3*n/4};
        
        int reach = n/4;
        
        int ans = -1;
        
        for(int i = 0;i<3;i++){
            
            int len = findLen(arr,arr[indices[i]]);
                        
            if(len > reach){
                
                return arr[indices[i]];
                
            }
            
        }
        
        return -1;
        
    }
};