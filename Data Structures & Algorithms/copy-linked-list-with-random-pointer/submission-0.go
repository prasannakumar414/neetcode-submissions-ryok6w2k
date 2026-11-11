/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
	new := make(map[*Node]*Node)
	curr := head
	var prev *Node
	for curr != nil {
		newNode := &Node{
			Val: curr.Val,
			Next: nil,
			Random: nil,
		}
		new[curr] = newNode
		if(prev != nil) {
			prev.Next = newNode
		}
		prev = newNode
		curr = curr.Next
	}
	curr = head
	newCurr := new[head]
	for curr != nil {
		newCurr.Random = new[curr.Random]
		curr = curr.Next
		newCurr = newCurr.Next
	}
	return new[head]
}
