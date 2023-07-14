class Solution {
public:
    
    void reverse(vector<int> &arr,int i,int j){
        
        while(i < j){
            
            swap(arr[i],arr[j]);
            i++;
            j--;
            
        }
        
    }
    
    void rotate(vector<int>& nums, int k) {
        
        //edge case
        
        k = k % nums.size();
        
//         if(nums.size() < k){
            
//             reverse(nums,0,nums.size()-1);
//             return;
            
//         }
        
        //since we have to shift it to right side
        //we are going to shift n-k elements to the left side
        //which is equivalent to shifting k elements to the right side
        k = nums.size() - k;
        
        //reverse 1st k elements
        reverse(nums,0,k-1);
        
        //reverse rest of the element
        reverse(nums,k,nums.size()-1);
        
        //reverse the entire array
        reverse(nums,0,nums.size()-1);
        
    }
};