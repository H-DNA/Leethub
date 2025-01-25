impl Solution {
    pub fn lexicographically_smallest_array(nums: Vec<i32>, limit: i32) -> Vec<i32> {
        let mut labeled_nums = nums.iter().enumerate().collect::<Vec<_>>();
        labeled_nums.sort_by(|(_, x), (_, y)| x.cmp(y));

        let mut partition_orders = vec![];
        let mut current_partition_order = vec![];

        let mut partitions = vec![];
        let mut current_partition = vec![];

        let mut last_num = labeled_nums[0].1;

        for (i, x) in labeled_nums {
            if (last_num - x).abs() <= limit {
                current_partition.push(x);
                current_partition_order.push(i);
            } else {
                partitions.push(current_partition);
                partition_orders.push(current_partition_order);
                current_partition = vec![x];
                current_partition_order = vec![i];
            }
            last_num = x;
        }
        partitions.push(current_partition);
        partition_orders.push(current_partition_order);
        let mut res = vec![0; nums.len()];

        for (mut partition, mut orders) in std::iter::zip(partitions, partition_orders) {
            orders.sort();
            partition.sort();
            for (num, i) in std::iter::zip(partition, orders) {
                res[i] = *num;
            }
        }
        res
    }
}