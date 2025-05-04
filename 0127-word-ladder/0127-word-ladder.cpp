class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Create dictionary
        unordered_set<string> dictionary(wordList.begin(), wordList.end());
        
        unordered_set<string> visited;
        int k=beginWord.size(), currlevel=0;
        string currStr,temp;

        //LevelOrderTravelsal:BFS
        //Nodes:GeneratenNodes:for each char traverse the string of size K
        //Edges:Lookup in Dict

        queue<pair<string,int>> q;
        q.push({beginWord,0});

        while(!q.empty()){

            currStr=q.front().first;
            currlevel=q.front().second;
            q.pop();
            visited.insert(currStr);
            if(currStr==endWord)
                return currlevel+1;
            //Generate all possible next nodes
            for(int i=0; i<k; i++){
                temp=currStr;
                for(int j=0; j<26; j++){
                    //Change the ith char of string
                    temp[i]='a'+j;
                    if(visited.find(temp)==visited.end() && dictionary.find(temp)!=dictionary.end()){
                        q.push({temp,currlevel+1});
                    }
                }
            }



        }
        
        return 0;
    }
};