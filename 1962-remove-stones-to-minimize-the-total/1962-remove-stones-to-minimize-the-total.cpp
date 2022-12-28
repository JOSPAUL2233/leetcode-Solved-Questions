class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int count = 0;
        
        priority_queue<int> q;
        
        for(int i = 0;i<piles.size();i++){
            
            q.push(piles[i]);
            
        }
        
        while(k>0){
            
            int temp = q.top();
            q.pop();
            
            if(temp%2==0){
                temp /= 2;
            }else{
                temp/=2;
                temp++;
            }
            
            q.push(temp);
            
            k--;
        }
        
        while(!q.empty()){
            
            count+=q.top();
            q.pop();
            
        }
        
        return count;
        
        
        
    }
};