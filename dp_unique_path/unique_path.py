# -*- coding:utf-8 -*-
import numpy as np
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        height=len(obstacleGrid)
        width=len(obstacleGrid[0])
        dialog_num=max(height,width)
        # path_num=np.zeros((height,width))
        path_num=[[0 for i in range(width)] for i in range(height)]
        # print dialog_num
        # z字形遍历，直到最后遍历到右下角
        for dialog_index in range(dialog_num):
            for x in range(min(dialog_index+1,height-1)):
                y=dialog_index-x
                if y > width-1:
                    continue
                # print y
                if x ==0 and y==0:
                    path_num[0][0]=1*(1-obstacleGrid[0][0])
                    continue
                elif x==0:
                    path_num[x][y]=path_num[x][y-1]*(1-obstacleGrid[x][y-1])
                elif y==0:
                    path_num[x][y]=path_num[x-1][y]*(1-obstacleGrid[x-1][y])
                else:
                    path_num[x][y]=path_num[x-1][y]*(1-obstacleGrid[x-1][y])+path_num[x][y-1]*(1-obstacleGrid[x][y-1])
                    # print x,y
        for dialog_index in range(dialog_num,height+width-1):
            for x in range(dialog_index-dialog_num+1,height):
                y=dialog_index-x
                path_num[x][y]=path_num[x-1][y]*(1-obstacleGrid[x-1][y])+path_num[x][y-1]*(1-obstacleGrid[x][y-1])
                # print x,y



        # for i in range(width):
        #     for j in range(height):
        #         print path_num[i][j]

        # print path_num[height-1][width-1]


        return path_num[height-1][width-1]

if __name__ == '__main__':
    origin=[[0,0,0],[0,1,0],[0,0,0]]
    path=Solution()
    path.uniquePathsWithObstacles(origin)
