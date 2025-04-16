class Solution {
public:
    //Populate the Freq of each task and evaluate max freq
    //Compute the count of elt with max freq
    //Compute total gaps rem: 
    //If total remaing gaps is less than total reamining elt, then we can extend the gaps to fill elts so ans is len of string
    //If gaps are more : ans is (total gaps rem+(count of max elt freq*max freq);
    

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int m=tasks.size(), maxFreq=0, countMaxFreq=0, gaps,remElt=0;
        for( int i=0; i<m;i++){
            freq[tasks[i]-'A']++;
            maxFreq=max(maxFreq,freq[tasks[i]-'A']);
        }
        for(int i=0; i<26; i++){
            if(freq[i]==maxFreq) countMaxFreq++;
        }

        //Total gaps:AB--AB--AB
        gaps=(n-countMaxFreq+1)*(maxFreq-1);

        remElt=m-countMaxFreq*maxFreq;

        //Gaps become -ve ie n<countMaxFreq: Ans will be m, because gaps req.
        if((n-countMaxFreq+1)<0) return m;
        //Gaps is less then remElt are more then we can expand gaps to fill elt in between gaps 
        if(remElt>gaps) return m;
        //Gaps are more and remElt are less
        return gaps+countMaxFreq*maxFreq;


        
        
    }
};