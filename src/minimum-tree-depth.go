package algo

import (
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	min := math.MaxInt

	var dfs func(node *TreeNode, currentDepth int)
	dfs = func(node *TreeNode, currentDepth int) {
		if node.Left == nil && node.Right == nil {
			if currentDepth < min {
				min = currentDepth
			}
		}

		if node.Left != nil {
			dfs(node.Left, currentDepth+1)
		}

		if node.Right != nil {
			dfs(node.Right, currentDepth+1)
		}
	}

	if root == nil {
		return 0
	} else {
		dfs(root, 1)
		return min
	}
}
