class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row = obstacleGrid.length;
        int column = obstacleGrid[0].length;                      //get the length of row and column.
        int[][] window = new int [2][column + 1];
        window[0][1] = 1;                                          //make window[1][1] = 1 as initialization.
        for(int i = 1; i < row + 1; i++){
            for(int j = 1; j < column + 1; j++){
                window[1][j] = (obstacleGrid[i - 1][j - 1] == 1)? 0 : window[0][j] + window[1][j-1];
            }
            for(int k = 0; k < column + 1; k++){                     //update the window
                window[0][k] = window[1][k];
                window[1][k] = 0; 
            }
        }
        return window[0][column];
    }
}