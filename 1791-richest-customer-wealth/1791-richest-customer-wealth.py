class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max_wealth = 0
        for customer in accounts:
            s = sum(customer)
            max_wealth = max(max_wealth, s)
        return max_wealth