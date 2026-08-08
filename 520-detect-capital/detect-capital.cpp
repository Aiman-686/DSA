class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital=0;

        //count upercase letters
        for(char ch:word){
            if(isupper(ch)){
                capital++;
            }
        }
        //case1:ALL uppercase
        if(capital==word.length())
        return true;

        //case2:ALL lowercase
        if(capital==0)
        return true;

        //case3: only first letter uppercase
        if(capital==1 && isupper(word[0]))
        return true;

        //Anything else is invalid
        return false;


        
    }
};