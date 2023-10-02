class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        map<int,int> freq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i:nums){
            
            freq[i]++;
            
        }
        
        for(auto i : freq){
            
            pq.push({i.second,i.first});
            
            if(pq.size() > k)
                pq.pop();
            
        }
        
        while(!pq.empty()){
            
                ans.push_back(pq.top().second);
                pq.pop();
            
        }
        
        return ans;
        
    }
};