class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>myset;
       bool ispresent=false;
       
       //push into the set
       for(auto it:wordList){
        if(it==endWord) ispresent=true;
        myset.insert(it);
       } 

       if(!ispresent) return 0;

       queue<string>q;
       q.push(beginWord);
       int depth=0;

        while(!q.empty()){
            int size=q.size();
            depth++;

            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();

                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(curr.compare(temp)==0){
                            continue;
                        }
                        if(temp.compare(endWord)==0){
                            return depth+1;
                        }
                        if(myset.find(temp)!=myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }


        }

    return 0;
    }
};