class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      std::vector<std::pair<int, int>> pixels;
      pixels.push_back({sr, sc});
      int oldColor = image[sr][sc];
      int m = image.size();
      int n = image[0].size();
      if (oldColor == newColor) return image;
      
      while (!pixels.empty()) {
        auto pixel = pixels[pixels.size() - 1];
        pixels.pop_back();
        int row = pixel.first, col = pixel.second;
        image[row][col] = newColor;
        if (row > 0 && image[row - 1][col] == oldColor)         {
          image[row - 1][col] = newColor;
          pixels.push_back({row - 1, col});
        }
        if (row < m - 1 && image[row + 1][col] == oldColor) {
          image[row + 1][col] = newColor;
          pixels.push_back({row + 1, col});
        }
        if (col > 0 && image[row][col - 1] == oldColor)         {
          image[row][col - 1] = newColor;
          pixels.push_back({row, col - 1});
        }
        if (row < n - 1 && image[row][col + 1] == oldColor) {
          image[row][col + 1] = newColor;
          pixels.push_back({row, col + 1});
        }
      }
      return image;
    }
};