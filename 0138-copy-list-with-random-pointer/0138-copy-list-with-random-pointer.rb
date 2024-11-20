# Definition for Node.
# class Node
#     attr_accessor :val, :next, :random
#     def initialize(val = 0)
#         @val = val
#		  @next = nil
#		  @random = nil
#     end
# end

def cloneNodeValue(node)
    node && Node.new(node.val)
end

# @param {Node} node
# @return {Node}
def copyRandomList(head)
    map = Hash.new(nil)
    clonedHead = cloneNodeValue head
    newHead = clonedHead 
    map[head] = clonedHead
    while (!head.equal? nil)
        if (!map.has_key? head.next)
            map[head.next] = cloneNodeValue head.next
        end
        clonedHead.next = map[head.next]
        if (!map.has_key? head.random)
            map[head.random] = cloneNodeValue head.random
        end
        clonedHead.random = map[head.random]
        clonedHead = clonedHead.next
        head = head.next
    end
    return newHead
end