#include"include.h"

/* Note: TLE
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return minimumTriangle(triangle, 0, 0);
    }
private:
    int minimumTriangle(vector<vector<int>> &triangle, int row, int col){
        int val = triangle[row++][col];
        if(row == triangle.size()) return val;
        return val + min(minimumTriangle(triangle, row, col), minimumTriangle(triangle, row, col+1));
    }
};
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int row = triangle.size()-2; row>=0; --row)
            for(int col = 0; col < triangle[row].size(); ++col)
                triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
        return triangle[0][0];
    }

};