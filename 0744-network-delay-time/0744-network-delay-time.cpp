class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Construct Graph: AdjList with each node pair<node,weight>
        vector<vector<pair<int,int>>> adjList(n+1);
        //Construct/Fill 
        for(auto t:times){
            adjList[t[0]].push_back({t[1],t[2]});
        }

        vector<int> visited(n+1,0);
        int count =0, res=0;

        //Declare a priority queue, insert weights first
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        //Push kth node as starting
        pq.push({0,k});

        while(!pq.empty()){
            pair<int,int>temp=pq.top();
            pq.pop();

            //Check id not already visited, because multiple same nodes with diff weights wiil exist
            if(visited[temp.second]) continue;
            //Mark Visited
            visited[temp.second]=1;
            count++;

            res=max(res,temp.first);

            for(auto nbr: adjList[temp.second]){//nbr is a pair
                pq.push({nbr.second+temp.first,nbr.first});
            }


        }

        return count==n?res:-1;
    }
};