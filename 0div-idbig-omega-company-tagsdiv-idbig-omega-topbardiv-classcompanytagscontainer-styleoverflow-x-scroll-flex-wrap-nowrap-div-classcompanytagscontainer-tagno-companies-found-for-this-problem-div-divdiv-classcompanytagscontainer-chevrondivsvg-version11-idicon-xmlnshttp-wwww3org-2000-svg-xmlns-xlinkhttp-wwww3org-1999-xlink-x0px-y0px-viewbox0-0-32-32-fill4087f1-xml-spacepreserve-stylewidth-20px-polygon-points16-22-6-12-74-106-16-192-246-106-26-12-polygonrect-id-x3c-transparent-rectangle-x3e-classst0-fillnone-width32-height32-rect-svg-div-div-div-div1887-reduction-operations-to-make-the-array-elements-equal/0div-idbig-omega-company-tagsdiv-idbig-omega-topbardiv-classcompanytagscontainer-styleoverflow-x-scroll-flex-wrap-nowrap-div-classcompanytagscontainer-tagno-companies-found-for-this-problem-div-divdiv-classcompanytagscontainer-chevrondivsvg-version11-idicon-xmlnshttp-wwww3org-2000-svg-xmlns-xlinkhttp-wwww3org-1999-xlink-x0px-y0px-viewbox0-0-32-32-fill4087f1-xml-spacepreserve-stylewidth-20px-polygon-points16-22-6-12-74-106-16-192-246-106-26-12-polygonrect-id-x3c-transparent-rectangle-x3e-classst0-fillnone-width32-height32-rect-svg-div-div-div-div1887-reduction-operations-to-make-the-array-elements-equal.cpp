class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int largest = nums.size()-1;
        
        int ans = 0;
        
        while(largest >= 0){
            
            int largestEle = nums[largest];
            
            while(largest >= 0 && nums[largest] == largestEle){
                largest--;
            }
            
            //gives the count of elements which are greater than the second largest element
            int count = nums.size() -1 - largest;
            
            //if the second largest element does exist, add it upto answer, otherwise break
            if(largest < 0)
                break;
            else
                ans += count;
            
            
        }
        
        return ans;
        
    }
};