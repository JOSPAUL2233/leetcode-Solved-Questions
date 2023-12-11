class Solution {
public:
    
    int findLen(vector<int> arr,int target){
        
        
        //FIND FIRST OCCURANCE USING BINARY SERACH
        
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
        
        //FIND LAST OCCURANCE USING BINARY SEARCH
        
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
        
        // RETURN THE LENGTH 
        
        return lastOccurance - firstOccurance + 1;
        
    }
    
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size();
        
        //possible answer will be in the indices n/4,n/2 and 3*n/4
        //since the freq should be more than n/4
        
        int freq = n/4;
        
        vector<int> indices = {n/4,n/2,3*n/4};
                
        int ans = -1;
        
        for(int i = 0;i<3;i++){
            
            //gets the frequency count using binary search
            int count = findLen(arr,arr[indices[i]]);
                        
            //if the frequency count is more than n/4, return the answer
            if(count > freq){
                
                return arr[indices[i]];
                
            }
            
        }
        
        //if the answer is not found, return -1
        return -1;
        
    }
};