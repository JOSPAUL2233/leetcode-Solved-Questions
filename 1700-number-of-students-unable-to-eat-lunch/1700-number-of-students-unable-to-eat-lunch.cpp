class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        stack<int> st;
        for(int i = sandwiches.size()-1;i>=0;i--){
            st.push(sandwiches[i]);
        }
        
        queue<int> que;
        for(int i = 0;i<students.size();i++){
            que.push(students[i]);
        }
        
        bool flag = false;
        while(!que.empty()){
            
            int size = que.size();
            flag = false;
            for(int i = 0;i<size;i++){
                
                int student = que.front();
                if(student==st.top()){
                    st.pop();
                    que.pop();
                    flag = true;
                    break;
                    
                }else{
                    que.push(que.front());
                    que.pop();
                }
                
            }
            if(!flag)
                break;
            
        }
        
        if(!flag)
            return que.size();
        else
            return 0;
        
        
    }
};