// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        if root.is_none() {
            return 0;
        }

        let rc = root.unwrap().clone();
        let node = rc.borrow_mut();
        
        if node.val < low {
            Solution::range_sum_bst(node.right.clone(), low, high)
        } else if node.val > high {
            Solution::range_sum_bst(node.left.clone(), low, high)
        } else {
            node.val + Solution::range_sum_bst(node.right.clone(), low, high) + Solution::range_sum_bst(node.left.clone(),low,high)
        }

    }
}