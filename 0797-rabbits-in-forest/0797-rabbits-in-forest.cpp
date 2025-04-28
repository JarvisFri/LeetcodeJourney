class Solution {
public:
    //Rabbits of same group will observe the same num
    int numRabbits(vector<int>& answers) {

        //Count freq of ans
        //Lets store all ans in an map
        unordered_map<int,int> ansFreq;
        int minCount=0, multiplier;

        for(int i=0; i<answers.size(); i++) ansFreq[answers[i]]++;

        for(auto pair: ansFreq){
            multiplier=0;
            multiplier= ceil((float)(pair.second)/(pair.first+1));

            minCount+=multiplier*(pair.first+1);
        }

        return minCount;
        
    }
};