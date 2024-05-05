class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for(int i=2; i<=n; i++){
            string laststring = ans;
            int l = ans.size();
            int j=0;
            ans="";
            while(j<l){
                int k = j;
                while(j<l && laststring[j] == laststring[k]){
                    k++;
                }
                ans += to_string(k-j)+laststring[j];
                j=k;
            }
        }
        return ans;
    }
};