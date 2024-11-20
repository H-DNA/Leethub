#include <utility>
class Solution {
public:
     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       long long swap_t = 0;
       long long same_tb = 0;
       
       int base_dom[2] = {tops[0], bottoms[0]};
       if (base_dom[1] == base_dom[0]) {
         ++same_tb;
         base_dom[1] = -1;
       }
       
       for (int i = 1; i < tops.size(); ++i){
         if (tops[i] == bottoms[i]) {
           if (tops[i] == base_dom[0]) {
             ++same_tb;
             base_dom[1] = -1;
           }
           else if (bottoms[i] == base_dom[1]) {
             ++same_tb;
             base_dom[0] = -1;
           }
           else return -1;
         }
         else {
           if (tops[i] != base_dom[0] and bottoms[i] != base_dom[1]) {
             ++swap_t;
             std::swap(tops[i], bottoms[i]);
           } 
           if (tops[i] == base_dom[0] and bottoms[i] == base_dom[1]) continue;
           else if (tops[i] == base_dom[0]) base_dom[1] = -1;
           else if (bottoms[i] == base_dom[1]) base_dom[0] = -1;
           else return -1;
         }
       }
    long long reverse = tops.size() - swap_t - same_tb;
    return swap_t < reverse ? swap_t : reverse;
  }
};