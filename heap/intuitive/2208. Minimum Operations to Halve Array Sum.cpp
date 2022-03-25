/*
simple problem
*/

class Solution {
public:
    int halveArray(vector<int>& a) {
        priority_queue<double> pq;
        double sum1=0,sum2=0;
        int ans=0;
        
        for(auto &x:a){
            sum1+=(1.0 * x);
            pq.push(1.0*x);
        }
        
        while(!pq.empty() && sum1>2.0*sum2)
        {
            double top = pq.top();
            pq.pop();
            sum2+=(1.0*top)/2.0;
            pq.push(1.0*top/2.0);
            ans++;
        }
        
        return ans;
    }
};