class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        set<int> s;
        
        s.insert(nums.begin(),nums.end());
        
        if(*s.begin()==0)return s.size()-1;
        else return s.size();
        
    }
};