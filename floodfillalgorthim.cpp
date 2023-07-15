#include<bits/stdc++.h>

 

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)

{

    int iniColor=image[x][y];

    int n=image.size();

    int m=image[0].size();

    vector<vector<int>>ans=image;

    

    queue<pair<int,int>>q;

    vector<vector<int>>vis(n,vector<int>(m,0));

    vis[x][y]=1;

    q.push({x,y});

    

    

    while(!q.empty()){

        int row=q.front().first;

        int col=q.front().second;

        q.pop();

        ans[row][col]=newColor;

 

        int drow[]={-1,0,+1,0};

        int dcol[]={0,+1,0,-1};

 

        for(int i=0;i<4;i++){

            int nrow=row+drow[i];

            int ncol=col+dcol[i];

 

            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m

                    &&!vis[nrow][ncol]&&image[nrow][ncol]==iniColor){

                        q.push({nrow,ncol});

                        vis[nrow][ncol]=1;

                        

                    }

        }

    }

 

    return ans;

}
