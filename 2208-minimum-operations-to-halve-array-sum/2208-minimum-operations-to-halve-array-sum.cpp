class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        priority_queue<double> q;
        
        double sum = 0;
        
        for(int i = 0;i<nums.size();i++){
            
            q.push(nums[i]);
            sum+=nums[i];
            
        }
        
        double half = sum/2;
        
        double count = 0;
        
        double sumItems = sum;
        
        
        while(sumItems>sum/2){
            
            double temp = q.top();
            q.pop();
            temp/=2;
            
            if(temp!=0)q.push(temp);
            
            count++;
            
            
            sumItems -= temp;
            
            
            // cout<<"sum: "<<sum<<endl;
            // cout<<"sumItem: "<<sumItems<<endl;
            // cout<<"sum-sumItems: "<<sum-sumItems<<endl;
            // cout<<"half: "<<half<<endl;
            // cout<<"count: "<<count<<endl<<endl;
            
        }
        
        
        
        return count;
        
    }
};