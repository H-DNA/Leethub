/*This solution doesn't take advantage of the fact that rows and columns are sorted - Just running raw selection algorithm on matrix.
Time complexity: O(n^2)
Memory complexity: O(1)
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        mt19937 mt;

        int left = 0;
        int right = n * n - 1;
        while (left < right) {
            //std::cout << left << ' ' << right << ' ' << k << '\n';
            const int pivot = uniform_int_distribution{left, right}(mt);
            const int pivot_e = linear_index(matrix, pivot);
            int less_right = left;
            int greater_left = right;
            for (int i = left; i <= greater_left; ++i) {
                int& i_e = linear_index(matrix, i);
                if (i_e < pivot_e) {
                    swap(i_e, linear_index(matrix, less_right));
                    ++less_right;
                }
                else if (i_e > pivot_e) {
                    swap(i_e, linear_index(matrix, greater_left));
                    --greater_left;
                    --i;
                }
            }
            
            if (less_right - left <= k - 1 && right - greater_left <= (right - left + 1) - k) return pivot_e;
            else if (less_right - left > k - 1)
                right = less_right - 1;
            else {
                k -= greater_left - left + 1;
                left = greater_left + 1;
            }
        }
        //return -1;
        return linear_index(matrix, left);
    }
    
    static int& linear_index(vector<vector<int>>& matrix, int id) {
        const int c = matrix.size();    //square matrix
        return matrix[id / c][id % c];
    }
    
};