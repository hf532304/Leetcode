class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int row_Size = matrix.size();
        if(matrix.size() == 0)
            return 0;
        int col_Size = matrix[0].size();
        int cur_Left = 0;
        int cur_Right = col_Size;
        int *left = new int[col_Size];
        int *right = new int[col_Size];
        int *height = new int[col_Size];
        fill_n(left, col_Size, 0);
        fill_n(right, col_Size, col_Size);
        fill_n(height, col_Size, 0);
        for(int i = 0; i < row_Size; i++){
            cur_Left = 0;
            cur_Right = col_Size;
            for(int j = col_Size - 1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j], cur_Right);
                }
                else{
                    cur_Right = j;
                    right[j] = col_Size;
                }
            }
            for(int j = 0; j < col_Size; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                    left[j] = max(left[j], cur_Left);
                }   
                else{
                    height[j] = 0;
                    cur_Left = j + 1;
                    left[j] = 0;
                }
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};