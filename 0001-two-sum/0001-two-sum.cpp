class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //do hashing
        map<int,int> hash;
        
        for(int i = 0;i<nums.size();i++){
            
            int rem = target - nums[i];
            
            //check for the pair
            if(hash.count(rem)){
                
                return { hash[rem] , i };
                
            }
               
            //push the current index into the hashmap
            hash[nums[i]] = i;
            
        }
               
        //if the answer was not found
        return {-1,-1};
        
    }
};