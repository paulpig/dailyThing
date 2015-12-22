//
//  main.cpp
//  dijkstra
//
//  Created by zhangwei on 15/12/18.
//  Copyright © 2015年 lkz. All rights reserved.
//

#include <iostream>
#include <string.h> 
using namespace std;
int main(int argc, const char * argv[]) {
    int row,line;
    int i,j,num=-1,k;
    int StartNum,nextNum;
    int **matrix;
    int *dist;
    int *tag;
    int *pre;
    int minDis=32767;
    cin>>row>>line;
    matrix=new int*[row];
    for(i=0;i<row;i++){
        matrix[i]=new int[line];
    }
    for(i=0;i<row;i++){
        for(j=0;j<line;j++){
            cin>>matrix[i][j];
        }
    }
    dist=new int[line];
    tag=new int[line];
    pre=new int[line];
    cout<<"choose who is starting:";
    cin>>StartNum;
    for(i=0;i<line;i++)
        dist[i]=matrix[StartNum][i];
    memset(tag,0,sizeof(int)*line);
    tag[StartNum]=1;
    nextNum=StartNum;
    pre[++num]=StartNum;
    for(k=1;k<row;k++){
    	minDis=32767;
    for(i=0;i<line;i++){
        if(dist[i]!=0&&dist[i]!=-1&&tag[i]!=1){
            if(dist[i]<minDis){
                minDis=dist[i];
                nextNum=i;
            }
        }
    }
    tag[nextNum]=1;
    pre[++num]=nextNum;
    for(j=0;j<line;j++){
        if(matrix[nextNum][j]!=0 && matrix[nextNum][j]!=-1&&tag[j]!=1){
            if(matrix[nextNum][j]+minDis<dist[j]){
                dist[j]=matrix[nextNum][j]+minDis;
            }
        }
    }
    }
    for(i=0;i<line;i++){
        cout<<dist[i];
    }
}
