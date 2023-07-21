class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

    
    //define left, right, top and bottom
        
    int top = 0;
    int bottom =matrix.size()-1;
    int left = 0;
    int right = matrix[0].size()-1;

    //store the total number of elements
    int max = matrix.size() * matrix[0].size();

    //keeps a track of number of elements visited
    int count = 0;

    vector<int> v;

    //loop will run till all the elements are visited
    while(count<max){

        // left to right
        for(int i = left;i<=right && count<max;i++){

            v.push_back(matrix[top][i]);
            count++;

        }
        top++;
        
        // top to bottom
        for(int i = top;i<=bottom && count<max;i++){

            v.push_back(matrix[i][right]);
            count++;

        }
        right--;

        // right to left
        for(int i = right;i>=left && count<max;i--){

            v.push_back(matrix[bottom][i]);
            count++;

        }
        bottom--;

        // bottom to top
        for(int i = bottom;i>=top && count<max;i--){
            v.push_back(matrix[i][left]);
            count++;

        }
        
        left++;

    }
        
    return v;
    }
};