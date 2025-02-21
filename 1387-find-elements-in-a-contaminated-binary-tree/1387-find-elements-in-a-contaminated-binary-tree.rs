use std::rc::Rc;
use std::cell::RefCell;

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
struct FindElements {
    root: Rc<RefCell<TreeNode>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FindElements {

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        FindElements {
            root: root.unwrap(),
        }
    }
    
    fn find_recur(&self, mut target: i32, current_node: &mut Option<Rc<RefCell<TreeNode>>>) {
        if target == 0 {
            return;
        }
        if (target & 1) == 1 {
            self.find_recur(target >> 1, current_node);
            if current_node.is_none() {
                return;
            }
            *current_node = current_node.clone().unwrap().borrow_mut().left.clone();
        } else {
            self.find_recur((target >> 1) - 1, current_node);
            if current_node.is_none() {
                return;
            }
            *current_node = current_node.clone().unwrap().borrow_mut().right.clone();
        }
    }

    fn find(&self, mut target: i32) -> bool {
        let mut root = Some(self.root.clone());
        self.find_recur(target, &mut root);
        root.is_some()
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * let obj = FindElements::new(root);
 * let ret_1: bool = obj.find(target);
 */