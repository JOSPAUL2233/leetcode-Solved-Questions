class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        
        for(int i = 0;i<nums.size();i++){
            
            freq[nums[i]]++;
            
        }
        
        priority_queue<pair<int,int>> que;
        vector<int> ans;
        
        for(auto i : freq){
        
            que.emplace(i.second,i.first);
            
        }
        
        for(int i = 0;i<k;i++){
            ans.push_back(que.top().second);
            que.pop();
        }
        
        return ans;
        
    }
};