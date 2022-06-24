class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        long long sum = 0;
        priority_queue<int> pq;
        for (auto num : target)
        {
            pq.push(num);
        }
        for (auto num : target)
        {
            sum += num;
        }
        while (pq.top() != 1)
        {
            sum -= pq.top();
            if (sum == 0 || sum >= pq.top())
                return false;
            int Lsum = pq.top() % sum;
            if (sum != 1 && Lsum == 0)
                return false;
            pq.pop();
            pq.push(Lsum);
            sum += Lsum;
        }
        return true;
    }
};