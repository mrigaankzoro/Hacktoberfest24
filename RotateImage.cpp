class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //transposing the matrix
        for(int i=0; i<n ; i++)
        {
            for(int j=i; j<n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reversing the row
        for(int i=0; i<n; i++)
        {
            int left =0;
            int right = n-1;
            while(left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
        
    }
};
