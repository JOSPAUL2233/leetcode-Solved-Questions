class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    map<int, int> tmp;
        
    for (int i = 0; i < nums.size(); ++i) {
        
          int ele = target-nums[i];
        
          if ( tmp.count(ele) ){

            return {tmp[ele], i};

          }

          tmp[nums[i]] = i;
        
    }
        
    return {-1, -1};
        
  }
    
};