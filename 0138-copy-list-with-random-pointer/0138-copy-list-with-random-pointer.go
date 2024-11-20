/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyNodeOnlyValue(node *Node) *Node {
    if node == nil {
        return nil;
    }
    
    return &Node { Val: node.Val };
}

func copyRandomList(head *Node) *Node {
    mapToClone := make(map[*Node]*Node);
    clonedHead := copyNodeOnlyValue(head);
    mapToClone[head] = clonedHead;
    curCloned := clonedHead;
    for head != nil {
        if mapToClone[head.Next] == nil {
            mapToClone[head.Next] = copyNodeOnlyValue(head.Next);
        }
        curCloned.Next = mapToClone[head.Next];
        if mapToClone[head.Random] == nil {
            mapToClone[head.Random] = copyNodeOnlyValue(head.Random);
        }
        curCloned.Random = mapToClone[head.Random];
        curCloned = mapToClone[head.Next];
        head = head.Next;
    }
    return clonedHead;
}