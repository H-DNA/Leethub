/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

import java.util.HashMap;

class Solution {
    public Node copyNodeOnlyValue(Node node) {
        if (node == null) {
            return null;
        }
        return new Node(node.val);
    }

    public Node copyRandomList(Node head) {
        HashMap<Node, Node> mapToClone = new HashMap<>();
        Node clonedHead = copyNodeOnlyValue(head);
        mapToClone.put(head, clonedHead);
        Node curClone = clonedHead;
        while (head != null) {
            if (!mapToClone.containsKey(head.next)) {
                mapToClone.put(head.next, copyNodeOnlyValue(head.next));
            }
            curClone.next = mapToClone.get(head.next);
            if (!mapToClone.containsKey(head.random)) {
                mapToClone.put(head.random, copyNodeOnlyValue(head.random));
            }
            curClone.random = mapToClone.get(head.random);
            curClone = curClone.next;
            head = head.next;
        }
        return clonedHead;
    }
}