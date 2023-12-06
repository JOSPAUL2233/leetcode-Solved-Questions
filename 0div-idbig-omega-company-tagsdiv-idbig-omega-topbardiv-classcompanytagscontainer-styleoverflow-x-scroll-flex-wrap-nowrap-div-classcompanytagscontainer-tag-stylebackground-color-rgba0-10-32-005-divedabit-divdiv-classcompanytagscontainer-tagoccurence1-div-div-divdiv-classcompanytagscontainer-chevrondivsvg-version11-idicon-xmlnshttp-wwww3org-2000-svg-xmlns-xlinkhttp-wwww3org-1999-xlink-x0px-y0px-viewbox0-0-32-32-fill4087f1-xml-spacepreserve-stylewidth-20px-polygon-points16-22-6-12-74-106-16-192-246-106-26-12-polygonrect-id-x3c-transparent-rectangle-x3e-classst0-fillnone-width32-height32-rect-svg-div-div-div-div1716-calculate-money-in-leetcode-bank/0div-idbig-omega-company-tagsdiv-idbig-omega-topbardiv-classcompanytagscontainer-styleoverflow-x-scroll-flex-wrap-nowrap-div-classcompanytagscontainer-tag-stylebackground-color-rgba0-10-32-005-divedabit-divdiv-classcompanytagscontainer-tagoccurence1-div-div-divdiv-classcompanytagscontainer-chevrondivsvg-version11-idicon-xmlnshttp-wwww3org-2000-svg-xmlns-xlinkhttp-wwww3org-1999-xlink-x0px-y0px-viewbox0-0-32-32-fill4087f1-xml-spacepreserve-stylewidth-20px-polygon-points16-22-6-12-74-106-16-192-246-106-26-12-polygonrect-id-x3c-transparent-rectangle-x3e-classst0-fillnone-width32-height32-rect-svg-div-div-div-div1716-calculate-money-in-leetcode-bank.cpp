class Solution {
public:
    int totalMoney(int n) {
        
        //ap first = a1
        //last = an = a1 + (n-1)d
        //sum = (n/2) * (first + last)
                        
        int first = 1;
        int last = 7;
        
        //for the first row
        int sum = (7) * (first + last) / 2;
        
        //now, let's find for the other rows using AP
        int row = n/7;
        
        first = sum;
        last = first + (row-1)*7;
        
        sum = row * (first + last)/2;
        
        //now, find the value for the last row
        //though it can be calcualted without loop also using the same sum formula
        for(int i = 0;i<n%7;i++){
            
            sum += row + i + 1;
            
        }
        
        return sum;
        
    }
};