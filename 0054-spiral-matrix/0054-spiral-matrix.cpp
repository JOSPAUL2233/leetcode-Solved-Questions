class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {


    int SR = 0;
    int ER =matrix.size()-1;
    int SC = 0;
    int EC = matrix[0].size()-1;

    int max = matrix.size() * matrix[0].size();

    int count = 0;

    vector<int> v;

    while(count<max){

        //raw1
        for(int i = SC;i<=EC && count<max;i++){

            v.push_back(matrix[SR][i]);
            count++;

        }
        SR++;
        
        //column1
        for(int i = SR;i<=ER && count<max;i++){

            v.push_back(matrix[i][EC]);
            count++;

        }
        EC--;

        //raw2
        for(int i = EC;i>=SC && count<max;i--){

            v.push_back(matrix[ER][i]);
            count++;

        }
        ER--;

        //col2
        for(int i = ER;i>=SR && count<max;i--){
            v.push_back(matrix[i][SC]);
            count++;

        }
        SC++;

    }
        
        return v;
 
    }
};