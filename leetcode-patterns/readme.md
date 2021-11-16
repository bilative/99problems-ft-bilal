## Leetcode - Patterns

I read the inspiring medium [post](https://mlengineer.io/amazon-applied-scientist-interview-europe-2021-6883cc22294b)(Amazon applied scientist interview (Europe, 2021)).

And I liked questions in [this](https://seanprashad.com/leetcode-patterns/) url, So I though that I can solve them and add the solutions here.

### [Missing Number](https://leetcode.com/problems/missing-number/)
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        
        total = sum(nums)
        must_be = n * (n+1) / 2
        return int(must_be - total)
```

### [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        empty = {}
        for i in nums:
            if i in empty:
                return True
            else:
                empty[i] = 'np'
        return False
```

### [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
#### 1 case was bomped bc of time limit exceedence. I'll fix it later.
```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        missing = [i for i in range(1, n+1) if not i in nums]
        return missing
```

### [Single Number](https://leetcode.com/problems/single-number/)
```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        twices = {}
        for i in nums:
            if i in twices:
                del twices[i]
            else:
                twices[i] = 1
        return list(twices.keys())[0]
```

### [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        max_profit = 0
        
        for i in prices[1:]:
            if i < buy:
                buy=i
    
            elif i > buy:
                max_profit = max((i - buy), max_profit)
                
        return max_profit
```
### [House Robber](https://leetcode.com/problems/house-robber)
```python
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        if len(nums) < 3:
            return max(nums)

        total_money = [nums[0], max(nums[:2])]
        
        for i in range(2, len(nums)):
            add_new = total_money[i-2] + nums[i]
            
            total_money.append(max(add_new, total_money[i-1]))
        
        return total_money[-1]
```
