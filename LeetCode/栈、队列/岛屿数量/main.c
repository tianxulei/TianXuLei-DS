struct node
{
    int x;
    int y;
    node(int a, int b) { x = a; y = b; }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    //int nums[10][10] = { 0 };
    
    struct node* a;
    int X=grid.size(), Y=grid[0].size();
    int x,y;
    vector<vector<int>> nums (X,vector<int>(Y));
    int flag = 0;
    queue<node> q;
    for(int i=0;i<X;++i)
        for (int j = 0; j < Y; ++j)
        {
            if (grid[i][j] == '1' && nums[i][j] != 1)
            {
                ++flag;
                //queue<node> q;
                q.push(node(i, j));
                nums[i][j] = 1;
                while (!q.empty())
                {
                    int size = q.size();
                    for (int k = 0; k < size; ++k)
                    {
                        node b = q.front();
                        a = &b; q.pop();
                        //左
                        x = a->x; y = a->y - 1;
                        if (y >= 0)
                        {                
                            if(grid[x][y] == '1' && nums[x][y] != 1)
                            {
                                q.push(node(x,y)); nums[x][y] = 1;                                
                            }
                        }
                        //右
                        x = a->x; y = a->y + 1;
                        if (y <Y)
                        {                
                            if(grid[x][y] == '1' && nums[x][y] != 1)
                            {
                                q.push(node(x, y)); nums[x][y] = 1;                                
                            }
                        }
                        //上
                        x = a->x - 1; y = a->y;
                        if (x >= 0 )
                        {                
                            if(grid[x][y] == '1' && nums[x][y] != 1)
                            {
                                q.push(node(x, y)); nums[x][y] = 1;                                
                            }
                        }
                        //下
                        x = a->x + 1; y = a->y;
                        if (x < X )
                        {                
                            if(grid[x][y] == '1' && nums[x][y] != 1)
                            {
                                q.push(node(x, y)); nums[x][y] = 1;                                
                            }
                        }
                    }
                    
                }
                cout<<"over";
            }
        }
        return flag;
    }
};
