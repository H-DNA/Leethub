// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::mem;

impl Solution {
    pub fn length_of_list(mut head: &Option<Box<ListNode>>) -> usize {
        let mut len = 0;
        while let Some(node) = head {
            len += 1;
            head = &node.next;
        }
        len
    }

    pub fn split_list_to_parts(mut head: Option<Box<ListNode>>, k: i32) -> Vec<Option<Box<ListNode>>> {
        let list_length = Solution::length_of_list(&head);
        let k = k as usize;
        let long_list_len = if list_length == 0 {
            0
        } else {
            1 + (list_length - 1) / k
        };

        let mut long_list_cnt = list_length % k;
        if long_list_cnt == 0 {
            long_list_cnt = k;
        }
        let mut res = vec![None; k];
        if long_list_len > 0 {
            for i in 0..long_list_cnt {
                res[i] = Some(Box::new(ListNode::new(head.as_ref().unwrap().val)));
                let mut last_elem = res[i].as_mut().unwrap();
                for j in 0..long_list_len - 1 {
                    let node = head.unwrap();
                    head = node.next;
                    last_elem.next = Some(Box::new(ListNode::new(head.as_ref().unwrap().val)));
                    last_elem = last_elem.next.as_mut().unwrap();
                }

                let mut node = head.unwrap();
                head = node.next;
                node.next = None;
            }
        }
        
        if long_list_len - 1 > 0 {
            for i in long_list_cnt..k {
                res[i] = Some(Box::new(ListNode::new(head.as_ref().unwrap().val)));
                let mut last_elem = res[i].as_mut().unwrap();
                for j in 0..long_list_len - 2 {
                    let node = head.unwrap();
                    head = node.next;
                    last_elem.next = Some(Box::new(ListNode::new(head.as_ref().unwrap().val)));
                    last_elem = last_elem.next.as_mut().unwrap();
                }

                let mut node = head.unwrap();
                head = node.next;
                node.next = None;
            }
        }

        res
    }
}