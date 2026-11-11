/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isValidBST(root *TreeNode) bool {
    return isValidNode(root, 1000000001, -1000000001)
}

func isValidNode(node *TreeNode,upper int, lower int) bool {
	if(node == nil) {
		return true
	}
	if(node.Val < upper && node.Val > lower) {
		return isValidNode(node.Left, node.Val, lower) && isValidNode(node.Right, upper, node.Val)
	}
	return false
}
