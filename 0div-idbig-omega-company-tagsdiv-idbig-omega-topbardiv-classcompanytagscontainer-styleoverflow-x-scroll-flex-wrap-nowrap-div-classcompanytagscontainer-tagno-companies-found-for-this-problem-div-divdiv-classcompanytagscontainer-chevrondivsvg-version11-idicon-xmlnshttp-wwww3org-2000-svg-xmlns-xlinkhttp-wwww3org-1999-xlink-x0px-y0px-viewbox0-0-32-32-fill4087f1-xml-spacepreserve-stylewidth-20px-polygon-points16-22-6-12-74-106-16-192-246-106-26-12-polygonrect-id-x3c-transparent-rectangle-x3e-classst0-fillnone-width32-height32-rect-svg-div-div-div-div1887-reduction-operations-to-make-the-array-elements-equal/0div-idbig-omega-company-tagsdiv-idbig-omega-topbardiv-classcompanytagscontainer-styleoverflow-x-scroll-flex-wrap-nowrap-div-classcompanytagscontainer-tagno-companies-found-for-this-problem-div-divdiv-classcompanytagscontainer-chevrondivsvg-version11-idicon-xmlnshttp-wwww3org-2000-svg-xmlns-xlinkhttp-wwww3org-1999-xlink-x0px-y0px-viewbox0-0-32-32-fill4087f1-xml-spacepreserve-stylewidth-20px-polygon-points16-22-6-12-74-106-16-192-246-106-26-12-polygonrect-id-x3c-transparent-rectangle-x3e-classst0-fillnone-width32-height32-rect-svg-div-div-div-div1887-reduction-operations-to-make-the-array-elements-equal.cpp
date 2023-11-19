class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int ptr = nums.size()-1;//keep a pointer which points to the largest element
        int ans = 0;
        
        while(ptr >= 0){
            
            //store the largest number
            int largestEle = nums[ptr];
            
            //move the pointer backwards until second largest is found
            while(ptr >= 0 && nums[ptr] == largestEle){
                ptr--;
            }
            
            //get the count of largest elements
            int count = nums.size() -1 - ptr;
            
            //if the second largest element does exist, end iteration here.
            //if it exists, then add the number of largest numbers which are converted(virtually)
            //to second largest , to the final answer
            if(ptr < 0)
                break;
            else
                ans += count;
            
        }
        
        return ans;
        
    }
};