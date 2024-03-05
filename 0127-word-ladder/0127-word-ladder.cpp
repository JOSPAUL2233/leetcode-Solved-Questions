class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //push all the wordList to set to have an easy check
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        //Let's go for BFS and find the shortest path taken to get to the endWord
        queue<string> que;
        que.push(beginWord);
        
        int level = 1;
        
        while(!que.empty()){
            
            int size = que.size();
            
            for(int i = 0;i<size;i++){
                
                string word = que.front();
                que.pop();
                
                if(word == endWord)
                    return level;
                
                for(int i = 0;i<word.size();i++){
                    
                    int original = word[i];
                    
                    //change the char to A-Z and check if it can make a path
                    for(char ch = 'a';ch<='z';ch++){
                        word[i] = ch;
                        if(st.find(word) != st.end()){
                            st.erase(word);
                            que.push(word);
                        }
                    }
                    
                    word[i] = original;
                    
                }
                
                
            }
            
            
            if(!que.empty())
                level++;
            
        }
        
        return 0;
        
    }
};