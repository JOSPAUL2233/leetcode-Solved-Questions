class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        //push all the wordList to set to have an easy check
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        //Let's go for BFS and find the shortest path taken to get to the endWord
        queue<string> que;
        que.push(beginWord);
        
        //keep track of level
        int level = 1;
        
        while(!que.empty()){
            
            int size = que.size();
            
            for(int i = 0;i<size;i++){
                
                //take out the word from queue
                string word = que.front();
                que.pop();
                
                //check if the word is found,if yes return the shortest path
                if(word == endWord)
                    return level;
                
                //iterate through all the chars of current word
                for(int i = 0;i<word.size();i++){
                    
                    int original = word[i];//keep track of original char
                    
                    //change the char to A-Z and check if it can make a path
                    for(char ch = 'a';ch<='z';ch++){
                        word[i] = ch;
                        if(st.find(word) != st.end()){
                            st.erase(word);
                            que.push(word);
                        }
                    }
                    
                    word[i] = original;//keep the original char
                    
                }
                
                
            }
            
            //increase level if exists
            if(!que.empty())
                level++;
            
        }
        
        return 0;
        
    }
};