ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(ll x,ll y)
{
    used[x][y]=1;
    for(ll i=0;i<4;i++)
    {
        ll nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>n)
            continue;
        if(!used[nx][ny])
            dfs(nx,ny);
    }
}
