//solve 209 first and iska to leetcode discussion khol
//209 wale code me bhi comments hai



class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        int sum = 0;
        int ans = INT_MAX;
        for( int i = 0; i<A.size(); i++){
            sum += A[i];
            if( sum >= K ){
                ans = min(ans, i+1);
            }
            while( pq.size() && sum - pq.top().first >= K ){
                auto p = pq.top();
                ans = min(ans, i-p.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == INT_MAX?-1:ans;
    }
};