class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        multimap<int,int> numtokey;
        int i=1;
        for(auto iter=numbers.begin();iter!=numbers.end();iter++){
            numtokey.insert(make_pair(*iter,i));
            ++i;
        }
        int count=1;
        for(auto iter=numbers.begin();iter!=numbers.end();iter++){
            int diff=target-*iter;
            auto numofdiff=numtokey.count(diff);
            auto temp=numtokey.find(diff);
            while(numofdiff){
                if(temp!=numtokey.end()&&count!=temp->second)
                        return {count,temp->second};
                else{
                    --numofdiff;
                    ++temp;
                }
            }
            ++count;
        }
        return {0,0};
    }
};
