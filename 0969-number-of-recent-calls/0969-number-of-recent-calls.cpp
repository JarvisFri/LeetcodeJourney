class RecentCounter {
public:
    RecentCounter() {
        //Constructor
        //Used to initialize class variables
        //We can use a global variable ans forget the constructor :')
    }

    //Declare queue as global variable
    queue<int> calls;
    int ping(int t) {
        //Store t in queue
        //pop from que while elt<t-3000
        calls.push(t);

        while(calls.front()<(t-3000)) calls.pop();

        return calls.size();
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */