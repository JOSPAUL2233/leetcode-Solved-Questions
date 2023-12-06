class Solution {
public:
    int totalMoney(int n) {
        
        int sum = 0;
        
        int row = n/7 + 1;
        int col = n%7;
        
        int count = n;
        
        for(int i = 1;i<=row;i++){
                        
            for(int j = i;j<i+7;j++){

                sum += j;
                count--;
                
                if(count==0)
                    return sum;
            }
        }
        
        return sum;
        
    }
};