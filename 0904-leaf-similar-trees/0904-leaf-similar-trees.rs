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
    pub fn collect_leaves(root: Option<Rc<RefCell<TreeNode>>>, seq: &mut Vec<i32>) {
        match root {
            None => (),
            Some(rc) => {
                let node = rc.borrow();
                if node.left.is_none() && node.right.is_none() {
                    seq.push(node.val);
                }
                if let Some(lrc) = node.left.clone() {
                    Solution::collect_leaves(node.left.clone(), seq);
                }
                if let Some(rrc) = node.right.clone() {
                    Solution::collect_leaves(node.right.clone(), seq);
                }
            }
        }

    }

    pub fn leaf_similar(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut seq1 = vec![];
        let mut seq2 = vec![];
        Solution::collect_leaves(root1, &mut seq1);
        Solution::collect_leaves(root2, &mut seq2);

        if seq1.len() != seq2.len() {
            false
        } else {
            for i in 0..seq1.len() {
                if seq1[i] != seq2[i] {
                    return false;
                }
            }
            true
        }
    }
}