class Solution {
public:
    
    string getRoman(int &num, map<int, string> numToRoman){
        
        int digit;
        
        //check for the intervals
        if(num >= 1000)
            digit = 1000;
        else if(num >= 900)
            digit = 900;
        else if(num >= 500)
            digit = 500;
        else if(num >= 400)
            digit = 400;
        else if(num >= 100)
            digit = 100;
        else if(num >= 90)
            digit = 90;
        else if(num >= 50)
            digit = 50;
        else if(num >= 40)
            digit = 40;
        else if(num >= 10)
            digit = 10;
        else if(num >= 9)
            digit = 9;
        else if(num >= 5)
            digit = 5;
        else if(num >= 4)
            digit = 4;
        else
            digit = 1;
            
        //modify the num
        num = num - digit;
            
        return numToRoman[digit];
        
    }
    string intToRoman(int num) {
        
        //map all the values to their corresponding roman letters
        map<int,string> numToRoman;
        
        numToRoman[1] = "I";
        numToRoman[4] = "IV";
        numToRoman[5] = "V";
        numToRoman[9] = "IX";
        numToRoman[10] = "X";
        numToRoman[40] = "XL";
        numToRoman[50] = "L";
        numToRoman[90] = "XC";
        numToRoman[100] = "C";
        numToRoman[400] = "CD";
        numToRoman[500] = "D";
        numToRoman[900] = "CM";
        numToRoman[1000] = "M";
        
        //initialize answer
        string ans = "";
        
        while(num > 0){
            
            //get the roman letter and update num in the function
            string roman = getRoman(num,numToRoman);
            
            //adds it to the answer
            ans += roman;
            
        }
        
        return ans;
        
    }
};