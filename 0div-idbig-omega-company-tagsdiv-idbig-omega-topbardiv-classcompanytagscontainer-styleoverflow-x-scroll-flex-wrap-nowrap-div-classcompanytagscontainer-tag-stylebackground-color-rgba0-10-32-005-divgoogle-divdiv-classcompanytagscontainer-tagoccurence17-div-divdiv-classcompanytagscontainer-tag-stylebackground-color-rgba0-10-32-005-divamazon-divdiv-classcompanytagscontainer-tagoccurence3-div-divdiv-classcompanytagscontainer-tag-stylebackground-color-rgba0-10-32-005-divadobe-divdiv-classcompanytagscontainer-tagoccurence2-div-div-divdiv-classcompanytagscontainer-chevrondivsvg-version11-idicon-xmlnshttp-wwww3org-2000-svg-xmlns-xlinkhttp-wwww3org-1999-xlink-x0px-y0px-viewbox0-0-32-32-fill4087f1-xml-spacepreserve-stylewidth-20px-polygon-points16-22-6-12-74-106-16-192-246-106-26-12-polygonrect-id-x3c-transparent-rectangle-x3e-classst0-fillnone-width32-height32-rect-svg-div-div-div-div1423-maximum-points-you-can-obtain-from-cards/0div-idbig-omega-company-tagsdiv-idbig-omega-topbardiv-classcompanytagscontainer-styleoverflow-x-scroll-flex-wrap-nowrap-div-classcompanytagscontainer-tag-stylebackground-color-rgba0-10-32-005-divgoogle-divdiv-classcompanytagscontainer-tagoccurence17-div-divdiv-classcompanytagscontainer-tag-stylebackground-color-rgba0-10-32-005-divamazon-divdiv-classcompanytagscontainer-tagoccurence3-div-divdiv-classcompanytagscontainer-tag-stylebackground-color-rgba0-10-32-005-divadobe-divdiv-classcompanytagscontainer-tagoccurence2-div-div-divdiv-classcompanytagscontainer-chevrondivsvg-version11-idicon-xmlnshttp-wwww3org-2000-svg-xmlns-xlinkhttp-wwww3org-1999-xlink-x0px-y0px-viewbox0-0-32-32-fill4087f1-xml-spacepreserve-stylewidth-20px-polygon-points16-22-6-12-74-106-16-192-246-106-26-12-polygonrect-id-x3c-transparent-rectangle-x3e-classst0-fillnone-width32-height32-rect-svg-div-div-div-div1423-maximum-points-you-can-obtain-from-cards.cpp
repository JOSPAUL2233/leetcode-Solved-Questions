class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        map<int,int> prefixSum;
        
        int sum = 0;
        
        //make the prefixSum hashmap
        for(int i = 0;i<cardPoints.size();i++){
            
            sum += cardPoints[i];
            prefixSum[i] = sum;
            
        }
        
        //this will be used in windowSum calculation
        //when left pointer is in first index
        prefixSum[-1] = 0;
        
        //answer
        int maxScore = 0;
        
        for(int left = 0;left<=k;left++){//do a dry run to understand this also why till kth index
            
            //understand this right pointer position formula by dry run
            int right = left + cardPoints.size() - 1 - k;
            
            //calculate the sum inside window
            int windowSum = prefixSum[right] - prefixSum[left-1];
            
            //calculate the score and store the maximum
            int score = sum - windowSum;
            maxScore = max(maxScore,score);
            
        }
        cout<<sum<<endl;
        return maxScore;
        
    }
};