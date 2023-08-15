class Solution {
public:

 string minWindow(string s, string t) {
     if(t.size()>s.size())return "";
     int n=s.size();
     unordered_map<char,int>mp;
     unordered_map<char,int>mp2;
     for(auto it: t){
         mp[it]++;
     }
     int j=0;
     int i=0;
     int ans=1e9;
     int final_i=-1;
     int final_j=-1;
     while(j<n){
         mp2[s[j]]++;
         while( i<n && j<n && mp.find(s[i])==mp.end() ){
             mp2[s[i]]--;
             if(mp2[s[i]]==0)mp2.erase(s[i]);
             i++;
         }
        
             while(i<n && mp2[s[i]]>mp[s[i]]){
                 mp2[s[i]]--;
                 i++;
             }
       
            bool f=0;
            for(auto it: mp){
                char c=it.first;
                int freq=it.second;
                if(mp2.find(c)==mp2.end())f=1;
                else{
                   if(mp2[c]<mp[c])f=1;
                    
                }
            }
            if(f==0){
                if(j-i+1<ans){
                    final_i=i;
                    final_j=j;
                    ans=min(ans,j-i+1);
                }
            }
     
         j++;
     }
     if(final_i==-1 && final_j==-1)return "";
return s.substr(final_i,final_j-final_i+1);
    
 }
};