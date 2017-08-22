# -*- coding: utf-8 -*-
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result=[]
        sort_num=sorted(nums,reverse=True)
        for i in range(len(sort_num)-2):
        	if i==0 or sort_num[i]!=sort_num[i-1]:
        		#转化为两个数字之和的问题了
        		letf=i+1
        		right=len(sort_num)-1
        		sum_two=0-sort_num[i]
        		while letf<right:
        			if sort_num[letf]+sort_num[right] == sum_two:
        				result.append([sort_num[i],sort_num[letf],sort_num[right]])
        				while letf< right and sort_num[letf]== sort_num[letf+1]:
        					# pass
        					letf=letf+1
        				while letf<right and sort_num[right]== sort_num[right-1]:
        					# pass
        					right=right-1
        				right=right-1
        				letf=letf+1
        			elif sort_num[letf]+sort_num[right] <sum_two:
        				right=right-1
        			else:
        				letf=letf+1
        print result

if __name__ =='__main__':
	temp=Solution()
	temp.threeSum([-1,0,1])