class Solution {
public:
    
    vector<int> leftGreater(vector<int> arr){
        
        vector<int> ans(arr.size(),0);
        int greater = INT_MIN;
        
        for(int i = 0;i<arr.size();i++){
            
            if(arr[i] > greater)
                greater = arr[i];
            
            ans[i] = greater;
            
        }
        
        return ans;
        
    }
    
    vector<int> rightGreater(vector<int> arr){
        
        vector<int> ans(arr.size(),0);
        int greater = INT_MIN;
        
        for(int i = arr.size()-1;i>=0;i--){
            
            if(arr[i] > greater)
                greater = arr[i];
            
            ans[i] = greater;
            
        }
        
        return ans;
        
    }
    
    int trap(vector<int>& height) {
        
        //create two arrays to store greatest element from left and right
        vector<int> prevGreater = leftGreater(height);
        vector<int> nxtGreater = rightGreater(height);
        
        int totalWater = 0;
        
        //iterate through all the elements
        for(int i = 0;i<height.size();i++){
            
            //get the greatest element from left and right
            int left = prevGreater[i];
            int right = nxtGreater[i];
            
            //get the min from them
            int smaller = min(left,right);
            
            //calculate the amound of water that can be trapped in that index
            int water = smaller - height[i];
            
            //add it to total water
            totalWater += water;
            
        }
        
        return totalWater;
        
    }
};