class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float("inf")
        sum_profit = 0
        for price in prices:
            min_price = min(min_price, price)      
            if price - min_price > 0:
                sum_profit += price - min_price
                min_price = price
           
        return sum_profit