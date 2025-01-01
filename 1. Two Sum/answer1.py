from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for n in range(len(nums)):
            for p in range(n, len(nums)):
                if(target-nums[n]==nums[p] and n !=p):
                    return([n,p])
        