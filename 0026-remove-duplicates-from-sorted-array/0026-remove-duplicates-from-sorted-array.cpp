class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> st;
        for(int i : nums)st.insert(i);
        
        int size = st.size();
        int ind = 0;
        
        for(auto it : st){
            
            nums[ind++] = it;
            
        }
        
        return size;
        
    }
};