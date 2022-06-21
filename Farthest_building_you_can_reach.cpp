class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //minheap
        
        priority_queue<int,vector<int>, greater<int>> minheap;
        //mih heap contains all the differences where ladder is utilised
        int last=heights[0];
        
        for(int i=1;i<heights.size();i++)
        {
            int diff=heights[i]-last;
            if(diff>0)
            {
                if(ladders>0) //utilise ladder
                {
                    ladders--;
                    minheap.push(heights[i]-last);
                }
                else
                {
                    int diff1=diff;
                    int diff2=INT_MAX;
                    if(!minheap.empty())
                    {
                        diff2=minheap.top();
                        minheap.pop();
                    }
                    
                    if(bricks>=min(diff1,diff2))
                    {
                        bricks-=min(diff1,diff2);
                        if(max(diff1,diff2)!=INT_MAX)
                        {
                            minheap.push(max(diff1,diff2));
                        }
                    }
                    else return i-1;
                }
            }
            
            last=heights[i];
        }
        
        return heights.size()-1;
    }
};