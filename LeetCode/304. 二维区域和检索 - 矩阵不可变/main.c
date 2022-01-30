/*给定一个二维矩阵 matrix，以下类型的多个请求：
计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
实现 NumMatrix 类：
NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 */
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            ans.push_back(vector<int>(n+1,0));
            for (int j = 1; j <= n; ++j) {
                ans[i][j] = ans[i][j - 1] + matrix[i][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int j = row1; j <= row2; ++j) {
            sum += (ans[j][col2+1] - ans[j][col1]);
        }
        return sum;
    }
    vector<vector<int>>ans;
};
