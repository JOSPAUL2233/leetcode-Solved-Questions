class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        
        //two pointers approach
        int left = 0;
        int right = numbers.size()-1;
        
        while(left < right){
            
            int sum = numbers[left] + numbers[right];
            
            //got the answer
            if(sum == target){
                return {left+1,right+1};
            }
            
            //decide the direction of moment of pointers
            if(sum > target)
                right--;
            else
                left++;
            
        }
        
        return {-1};
            
    }
};