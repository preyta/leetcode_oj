class Solution {
public:
       int lengthOfLongestSubstring(string s) {
            int startpos=0,maxlength=0;
            unordered_map<char,int> table;
            for(int i=0;i<s.size();i++){
                    char currentletter=s.at(i);
                    auto iter=table.find(currentletter);
                    if(iter==table.end()){
                            table[currentletter]=i;
                            if(i==s.size()-1)
                                maxlength=max(i-startpos+1,maxlength);
                    }
                    else{//don't erase element,just check its position
                            if(iter->second>=startpos){
                                maxlength=max(i-startpos,maxlength);
                                startpos=iter->second+1;
                                table[currentletter]=i;
                            }
                            else{
                                table[currentletter]=i;
                                if(i==s.size()-1)
                                    maxlength=max(i-startpos+1,maxlength);
                            }
                    }
            }
            return maxlength;
        }
};