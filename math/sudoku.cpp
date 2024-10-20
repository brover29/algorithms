    #include<bits/stdc++.h>
using namespace std;
#define N 9

int grid[N][N];

bool isSafeInRow(int& row,int value){
    for(int i=0;i<N;i++){
        if(grid[row][i]==value){
            return false;
        }
    }
    return true;
}

bool isSafeInCol(int& col,int value){
    for(int i=0;i<N;i++){
        if(grid[i][col]==value){
            return false;
        }
    }
    return true;
}

bool isSafeBox(int& row,int& col, int value){
    int rowFactor=row-row%3;
    int colFactor=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rowFactor][j+colFactor]==value){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int& row,int& col,int value){
    if(isSafeInRow(row,value) && isSafeInCol(col,value) && isSafeBox(row,col,value)){
        return true;
    }
    return false;
}

bool findEmptyLocation(int& x,int& y){
    int Min=10,cnt=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(grid[i][j]==0){
                int cnt=0;
                for(int k=1;k<=9;k++)
                {
                    if (isSafe(i,j,k))
                        cnt++;
                }
                if(cnt<Min)
                {
                    Min=cnt;
                    x=i;
                    y=j;
                }
            }
        }
    }
    if(Min<10)
        return true;
    return false;
}



bool solveSudoku(){
    int row,col;
    if(!findEmptyLocation(row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(isSafe(row,col,i)){
            grid[row][col]=i;
            if(solveSudoku()){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}

void solve(){
    string inp[N];
    string s;
    for(int i=0;i<N;i++){
        getline(cin,inp[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(inp[i][j]=='.'){
                grid[i][j]=0;
            }
            else grid[i][j]=inp[i][j]-'0';
        }
    }
    solveSudoku();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<'\n';
        cout<<endl;
    }
}



int main(void){
    int t;
    cin>>t;
    cin.ignore();
    t=1;
    for(int i=1;i<=t;i++){
       // cout<<"Case "<<i<<": "<<endl;
        solve();
    }
    return 0;
}
