class Solution {
public:
   
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i = 1;i < nums.size();i++){
            while(i-pq.top().second > k) {
                pq.pop();
            }
            int sum = pq.top().first;
            int index = pq.top().second;
            pq.push({sum+nums[i],i});
        }
        while(pq.top().second != nums.size()-1){
            pq.pop();
        }
        return pq.top().first;
    }
};