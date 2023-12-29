class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        //get the sum and get the sum of largest char
        int sum = 0;
        int largestSum = 0;
        
        for(int i = 0;i<colors.size();i++){
            
            sum += neededTime[i];
            
            int largest = neededTime[i];
            
            while(i+1 < colors.size() && colors[i] == colors[i+1]){
                                
                largest = max(largest,neededTime[i+1]);
                i++;
                
                sum += neededTime[i];
                
            }
            
            // cout<<largest<<endl;
            largestSum += largest;
            
        }
        
        return sum - largestSum;
        
    }
};