class Solution {
public:
    
    void reverse(vector<int> &nums,int left,int right){
        
        while(left < right){
            
            swap(nums[left],nums[right]);
            left++;
            right--;
            
        }
        
    }
    
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        //edge case : if there is only one element, return the array
        if(n == 1)
            return;
        
        //step 1 : find the breaking point(an element which is lesser than the next element)
        
        int ind = -1;
        for(int i = n-2;i>=0;i--){
            
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
            
        }
        
        //step 2 : if there is no breaking point, then reverset it
        //         otherwise go for the algorithm
        
        if(ind == -1){//if there is no breaking point
            
            reverse(nums,0,n-1);
            
        }else{//if there is a breaking point
            
        //find the smaller element from right of breaking point
        //which is just greater than the breaking point and swap it

            for(int i = n-1 ; i >= ind ; i--){
                
                //if an element is found which is greater than the break point
                if(nums[i] > nums[ind]){
                    
                    swap(nums[ind] , nums[i]);
                    break;
                    
                }
                
            }
            
            //sort the elements to the right side of breaking point
            //so basically they are in decreasing order now, so just reverse them

            reverse(nums,ind+1,n-1);            
            
        }
        
        
    }
};