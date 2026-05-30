class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return None
        output = 0
        min_price = prices[0]
        for i in range(1, len(prices)):
            output = max(output, prices[i]-min_price)
            min_price = min(min_price, prices[i])

        return output
        