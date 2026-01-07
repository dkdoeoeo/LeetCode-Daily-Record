class Solution(object):
    def twoSum(self, nums, target):
        for i in range(len(nums)):
            a=nums[i]
            for j in range(i+1,len(nums)):
                b=a+nums[j]
                if b==target:
                    return [i,j]
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """