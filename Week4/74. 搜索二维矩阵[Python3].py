#binary search
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        
        def bs(arr,target):
            low,high = 0,len(arr)-1
            
            while low <= high:
                mid = (low+high)//2
                guess = arr[mid]
                
                if guess < target:
                    low = mid+1
                if guess > target:
                    high = mid-1 
                if guess == target:
                    return True  
            return False
        
        for row in matrix:
            if row:
                # check last value to see if < target, if it is go to next row 
                if row[-1] < target:
                    continue 
                else:
                    # run the search 
                    if bs(row,target):
                        return True 
        
        return False