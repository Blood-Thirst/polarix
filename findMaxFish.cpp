class Solution {
public:
    int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
    vector<vector<int>>vis;
    bool valid(int x,int y)
    {
        if(x<0 || y<0 || x==vis.size() || y==vis[0].size())
        {
            return 0;
        }
        return 1;
    }
    int dfs(int x,int y,vector<vector<int>>&grid)
    {
        int ans=grid[x][y];
        vis[x][y]=1;
        for(int i=0;i<4;++i)
        {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny])
            {
                ans+=dfs(nx,ny,grid);
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }        
        return ans;
    }
};
