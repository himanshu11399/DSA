class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = [0] * len(nums)
        for i, x in enumerate(nums):
            temp[(i + k) % len(nums)] = x

        for i, x in enumerate(temp):
            nums[i] = x
