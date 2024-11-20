class Solution {
public:
    int solution1(vector<int>& height) {
        int ans = 0;
        vector<int> asc;
        // asc
        asc.push_back(0);
        int n = height.size();
        for (int i = 1; i < n; i++) {
            if (height[asc.back()] <= height[i]) {
                asc.push_back(i);
            }
        }
        int end = asc.back();
        int h = height[0];
        for (int i = 1; i < asc.size(); i++) {
            for (int j = asc[i - 1]; j < asc[i]; j++) {
                ans += (h - height[j]);
            }
            h = height[asc[i]];
        }

        // desc
        asc.clear();
        asc.push_back(height.size() - 1);
        for (int i = n - 2; i >= end; i--) {
            if (height[asc.back()] <= height[i]) {
                asc.push_back(i);
            }
        }
        h = height.back();
        for (int i = 1; i < asc.size(); i++) {
            for (int j = asc[i - 1]; j > asc[i]; j--) {
                ans += (h - height[j]);
            }
            h = height[asc[i]];
        }

        return ans;
    }
    
    int solution2(vector<int>& height) {
        int l = 0, r = height.size() - 1, l_max = height[0], r_max = height.back();
        int ans = 0;
        while (l < r) {
            while (l < r && height[l] <= height[r]) {
                l_max = max(l_max, height[l]);
                ans += l_max - height[l];
                l++;

            }
            while (l < r && height[l] > height[r]) {
                r_max = max(r_max, height[r]);
                ans += r_max - height[r];
                r--;
            }
        }
        return ans;

    }
    int trap(vector<int>& height) {
        //return solution1(height);
        return solution2(height);
        
    }
};
