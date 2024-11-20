# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

require 'set'
# @param {ListNode} head
# @return {Boolean}
def hasCycle(head)
    traverse = Set[];
    while !(head.equal? nil)
        if traverse.include?(head) 
            return true
        end
        traverse.add head
        head = head.next
    end
    false
end