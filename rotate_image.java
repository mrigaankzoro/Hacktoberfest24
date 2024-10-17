class Solution {
    public void rotate(int[][] matrix) {
        int l=matrix.length;
        int c=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(i<j){
                int t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
                }else
                    continue;
            }
        }

        for(int i=0;i<l;i++){
            for(int j=0;j<l/2;j++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[i][l-1-j];
                matrix[i][l-1-j]=t;
            }
        }

        

        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                System.out.print(matrix[i][j]+" ");
            }
        System.out.println();
        }    
    }
    
    public static void main (String args[]){
        int m[][]={{1,2,3},{4,5,6},{7,8,9}};
        //m={{1,2,3},{4,5,6},{7,8,9}};
        Solution obj= new Solution();
        obj.rotate(m);
    }
}