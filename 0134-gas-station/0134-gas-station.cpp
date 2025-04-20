class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //Start from each index 
        //Check if we can complete a loop
        //Optimization: If I am not able to taraverse from S to E then i wont be able to traverse from any S' between S & E
        // If i start at S: F(s')>=0 but if i start at S': F(S')=0 

        int n=gas.size(), countTraversed=0, currTank=0, k,i=0,j=0;

        //Increment i: and check if we can reach from i to n
        while(i<n){
            currTank+=gas[i]-cost[i];

            cout<<currTank<<" ";
            if(currTank>=0){
                countTraversed++;
                i++;
            }else{
                currTank=0;
                countTraversed=0;
                i++;
                j=i;
            };

        };

        if(countTraversed==0) return -1;

        //Round trip till countTraversed==n
        i=0;
        while(countTraversed<=n){
           currTank+=gas[i]-cost[i];
           cout<<currTank<<" ";
           if(currTank>=0){
            countTraversed++;
            i++;
           } else{
            return -1;
           }
        }
        return j;

        // for(int i=0; i<n; i++){
        //     currTank=0;
        //     countTraversed=0;
        //     k=i;
        //     while(countTraversed<=n){
        //         //Fill up the tank
        //         currTank+=gas[k];
        //         //GoTo next station

        //         currTank-=cost[k];
                
        //         cout<<currTank<<" ";
        //         if(currTank<0) break;

        //         //updateTraversed
        //         countTraversed++;
        //         //updatei:
        //         k=(k+1)%n;
        //     }

        //     if(countTraversed>n) return i;

        //     else{
        //         i+=countTraversed;
        //     };

        
        // }
        // return -1;
        
    }
};