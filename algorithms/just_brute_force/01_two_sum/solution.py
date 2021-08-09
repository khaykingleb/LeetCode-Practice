def two_sum(self, nums, target):
    """
    Params:
      nums: List[int]
      target: int
    Returns:
      ans: List[int]
    """
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] + nums[j] == target:
                ans = [i, j]
                return ans
