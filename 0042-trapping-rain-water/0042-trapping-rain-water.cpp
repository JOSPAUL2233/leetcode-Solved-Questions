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
        
        //create two arrays to store previous greater element and next greater element
        vector<int> prevGreater = leftGreater(height);
        vector<int> nxtGreater = rightGreater(height);
        
        int ans = 0;
        
        for(int i = 0;i<height.size();i++){
            
            int left = prevGreater[i];
            int right = nxtGreater[i];
            
            int smaller = min(left,right);
            
            int water = smaller - height[i];
            
            ans += water;
            
        }
        
        return ans;
        
    }
};