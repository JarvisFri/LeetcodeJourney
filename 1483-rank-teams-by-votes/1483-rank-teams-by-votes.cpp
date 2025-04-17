class Solution {
public:
    //Ranks: 1 to 26 since length of votes is 26
    //Teams: A to Z : 26
    //Lets keep freq array <vector<vector<int>>(26, vector<int>(26,0))
    //Here 1st arrays represents rank 1 votes and so on..
    //To calculate order
    
    string rankTeams(vector<string>& votes) {

        vector<vector<int>> freq(26,vector<int>(26,0));
        for(int i=0; i<votes.size(); i++){
            for(int j=0; j<votes[i].size();j++){
                freq[j][votes[i][j]-'A']+=1;
            }
        }

        string ans=votes[0];

        sort(ans.begin(), ans.end(), [freq](char& a, char & b){
        for(int i=0; i<freq.size(); i++){
            if(freq[i][a-'A']!=freq[i][b-'A']) return (freq[i][a-'A']>freq[i][b-'A']);
            }
        return a<b;
        }  );

        return ans;
        
    }
};