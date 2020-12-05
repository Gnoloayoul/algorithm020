学习笔记

1、要背的
递归模板 python
分治模板 python C

2、用模板来做题目

236. 二叉树的最近公共祖先
[python3]
        # recursion terminator
        if root is None : return None
        # process logic in current level
        if root.val == p.val : return p
        elif root.val == q.val : return q
        # drill down
        else :
            isFoundLeft = self.lowestCommonAncestor(root.left, p, q)
            isFoundRight  self.lowestCommonAncestor(root.right, p, q)
            if isFoundLeft is None or isFoundRight is None :
                return isFoundLeft or isFoundRight
            else :
                return root
        #revert the current level status if needed


105. 从前序与中序遍历序列构造二叉树
[python3]
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        #recurent terminator
        if inorder :
            #process logic in current level
            rootVal = preorder.pop(0)
            i = inorder.index(rootVal)
            root = TreeNode(rootVal)
            #drill down
            root.left = self.buildTree(preorder, inorder[0 : i])
            root.right = self.buildTree(preorder, inorder[i + 1 :])
            return root
            #revert the current level status if needed

但国外大神的更漂亮，虽然也更难懂......

class Solution:
    def __init__(self):
        self.inorder_index = {}
        self.preorder = []
        self.inorder = []
        self.n = 0
    
    def build(self, pi, pj, ii, ij):
        # pi, pj: the start and end of preorder array
        # ii, ij: the start and end of inorder array
        
        if pi == pj:
            return TreeNode(self.preorder[pi])
        if pi > pj:
            return None
        
        root_val = self.preorder[pi]
        # rest of preorder: pi+1, pj
    
        root = TreeNode(root_val)
        pivot = self.inorder_index[root_val]
        
        # number of nodes in left: pivot-ii
        root.left = self.build(pi+1, pi+pivot-ii, ii, pivot-1)
        root.right = self.build(pi+1+pivot-ii, pj, pivot+1, ij)
        
        return root
        
    
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        
        self.n = len(preorder)
        if not self.n: return None
        
        self.preorder = preorder 
        for i,e in enumerate(inorder):
            self.inorder_index[e] = i
        
        return self.build(0, self.n-1, 0, self.n-1)


77. 组合
[python3]
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.answer = []
        self.k = k
        self.n = n
        self.generateKPairs(solution=[], num=1)
        return self.answer
    
    def generateKPairs(self, solution, num):
        if len(solution) == self.k:
            self.answer.append(solution)
        elif len(solution) < self.k:
            for i in range(num, self.n + 1):
                self.generateKPairs(solution + [i], i+1)

这里我比较难看出其中的递归······

46. 全排列
[python3]
class Solution:
	def permute(self, nums: List[int]) -> List[List[int]]:
        #recursion terminator
		if len(nums)<=1:
			return [nums]
        #process logic in current level
		ans=[]
        #drill down
		for i,j in enumerate(nums):
			num=nums[:i]+nums[i+1:]
			for _ in self.permute(num):
				ans.append([j]+_)
		return ans
        #revert the current level status if needed


47. 全排列 II
[python3]
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        #recursion terminator
        if len(nums) <= 1:
            return [nums]
        else:
        #process logic in current level 
            a = []
            for x in list(set(nums)):
                i = nums.index(x)
                xs = nums[:i] + nums[i+1:]
                #drill down
                for p in self.permuteUnique(xs):
                    a.append([x] + p)
            return a
        #revert the current level status if needed

3、一点心得
老师给出的递归的模板，不光只是用在解题上，也能用来读懂（学习）他人的代码。