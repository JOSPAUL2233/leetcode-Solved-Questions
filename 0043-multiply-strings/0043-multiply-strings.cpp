class Solution {
public:
    string multiply(string num1, string num2) {
        
        vector<int> vec(num1.size() + num2.size(), 0);
        
        for(int i = num1.size()-1;i>=0;i--){
            
            
            for(int j = num2.size()-1;j>=0;j--){
                
                
                int sum = (num1[i] - '0') * (num2[j] - '0');
                sum += vec[i+j+1];          //taking sum by also adding with prev carry
                
                vec[i+j+1] = sum%10;          // storing the result 
                vec[i+j] += sum/10;              // storing the carry to the next index
                
            }
            
            
            
        }
        
        //remove all the leading zeroes
        
        int i = 0;
        while(i<vec.size() && vec[i] == 0)i++;
        
        
        //storing the answer
        string ans;
        while(i<vec.size()){
            
            char ch = vec[i] + '0';
            
            ans.push_back(ch);

            i++;
            
        }
        
        if(ans.size() == 0)return("0");
        return ans;
        
    }
};