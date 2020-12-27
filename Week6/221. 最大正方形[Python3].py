class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        row, col = len(matrix), len(matrix[0])
        
        dp = [[0]*(col+1) for i in range(row+1)]
        
        max_square_len = 0
        for i in range(1, row+1):
            for j in range(1, col+1):
                if matrix[i-1][j-1] == "1":
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    max_square_len = max(dp[i][j], max_square_len)
                    
        return max_square_len * max_square_len