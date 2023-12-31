class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int output;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j]){
                    if(output < j-i-1){
                        output = j-i-1;
                    }
                }
            }
        }
        if(output >= 0){
            return output;
        }
         else return -1;
        
    }
};