class Solution {
public:
    int maxTurbulenceSizeSub(vector<int>& arr) {
      if (arr.size() == 1) return 1;  
      int tmax = 2, tcount = 2;
      bool gsg;
      if (arr[0] > arr[1]) gsg = true; else gsg = false;
      for (int i = 2; i < arr.size(); ++i) {
          if (tcount % 2 == not gsg and arr[i] > arr[i - 1] or
              tcount % 2 == gsg and arr[i] < arr[i - 1]) ++tcount;
          else {
            if (tmax < tcount) tmax = tcount;
            tcount = 2;
            gsg = arr[i] < arr[i - 1];
          }
       }
      if (tmax < tcount) tmax = tcount;
      return tmax;
    }
    int maxTurbulenceSize(vector<int>& arr) {
      int i = 0;
      int max = -1;
      int d;
      while (i < arr.size()) {
        std::vector<int> tmp;
        tmp.push_back(arr[i++]);
        while (i < arr.size() and arr[i] != arr[i - 1]) tmp.push_back(arr[i++]);
        if (max < (d = maxTurbulenceSizeSub(tmp))) max = d; 
      }
      return max;
    }
};