class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);

        for(int i = 1;i<=n;i++){

            int num = i;
            int count = 0;

            for(int j = 0;j<32;j++){

                if(num&1)count++;
                
                num>>=1;
                
            }

            ans.push_back(count);

        }

        return ans;
    }
};