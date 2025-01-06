class Solution {
public:
    vector<int> minOperations(string boxes) {
      vector<int> res;
      res.reserve(boxes.size());
      unsigned int onesToTheRight = 0;
      unsigned int onesToTheLeft = 0;
      unsigned int currentTotalSteps = 0;
      const unsigned int len = boxes.length();
      for (unsigned int i = 0; i < len; ++i) {
        if (i > 0) {
          onesToTheRight += (boxes[i] == '1');
        }
        currentTotalSteps += (boxes[i] == '1' ? i : 0);
      }
      for (unsigned int i = 0; i < len; ++i) {
        res.push_back(currentTotalSteps);
        currentTotalSteps -= onesToTheRight;
        if (i < len - 1) {
          onesToTheRight -= (boxes[i + 1] == '1');
        }
        onesToTheLeft += (boxes[i] == '1');
        currentTotalSteps += onesToTheLeft;
      }

      return res;
    }
};