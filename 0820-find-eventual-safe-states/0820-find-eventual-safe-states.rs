#[derive(PartialEq, Clone)]
enum State {
    WHITE,
    GRAY,
    BLACK,
}

impl Solution {
    pub fn dfs(root: i32, graph: &Vec<Vec<i32>>, visited: &mut Vec<State>, in_res: &mut Vec<bool>) -> bool {
        let mut in_cycle = false;
        for neighbor in graph[root as usize].iter() {
            if visited[*neighbor as usize] == State::BLACK {
                if !in_res[*neighbor as usize] {
                    in_res[root as usize] = false;
                    in_cycle = true;   
                }
                continue;
            }
            if visited[*neighbor as usize] == State::GRAY {
                in_res[root as usize] = false;
                in_res[*neighbor as usize] = false;
                in_cycle = true;
                continue;
            }
            visited[*neighbor as usize] = State::GRAY;
            if Solution::dfs(*neighbor, graph, visited, in_res) {
                in_cycle = true;
                in_res[root as usize] = false;
            }
            visited[*neighbor as usize] = State::BLACK;
        }
        in_cycle
    }
    pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
        let vertices = graph.len();
        let mut visited = vec![State::WHITE; vertices];
        let mut in_res = vec![true; vertices];
        let mut res = vec![];
        for i in 0..vertices {
            if visited[i] == State::BLACK {
                continue;
            }
            visited[i] = State::GRAY;
            if Solution::dfs(i as i32, &graph, &mut visited, &mut in_res) {
                in_res[i] = false;
            }
            visited[i] = State::BLACK;
        }
        for i in 0..vertices {
            if in_res[i] {
                res.push(i as i32);
            }
        }
        res
    }
}