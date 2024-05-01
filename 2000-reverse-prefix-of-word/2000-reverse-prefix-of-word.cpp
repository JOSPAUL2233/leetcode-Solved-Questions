class Solution {
public:

    void reverse(string &s,int left,int right){

        while(left<right)
            swap(s[left++],s[right--]);

    }

    string reversePrefix(string word, char ch) {

        for(int i = 0;i<word.size();i++){
            if(word[i] == ch){
                reverse(word,0,i);
                break;
                }
        }

        return word;
        
    }
};