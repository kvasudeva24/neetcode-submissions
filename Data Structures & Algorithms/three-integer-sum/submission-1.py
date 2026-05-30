from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()  # Sort the array first
        
        for i, a in enumerate(nums):
            if i > 0 and a == nums[i-1]:  # Skip duplicates for the first element
                continue
            
            l, r = i + 1, len(nums) - 1
            
            while l < r:
                threesum = a + nums[l] + nums[r]  # Correct sum calculation
                
                if threesum > 0:
                    r -= 1
                elif threesum < 0:
                    l += 1
                else:
                    result.append([a, nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l - 1]:  # Skip duplicates for the second element
                        l += 1
        
        return result
