class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size()-1;
        
        int left = 0;
        int right = n;
        
        int maxArea = 0;
        
        
        for(int i = 0;i<n;i++){
            
            int width = right-left;
            int area = 0;
            
            if(height[left]<height[right]){
                
                area = width*height[left];
                left++;
                maxArea = max(maxArea,area);
                
                
            }else{
                
                area = width*height[right];
                right--;
                maxArea = max(maxArea,area);
                
            }
            
        }
        return maxArea;
        
    }
};