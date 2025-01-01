from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}  
        
        for index, num in enumerate(nums):
            find = target - num
            if find in num_map:
                return [num_map[find], index]
            
            num_map[num] = index
