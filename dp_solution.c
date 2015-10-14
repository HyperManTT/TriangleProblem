int dpTriangle(int **triangle, int **mem, int num){
    int i, j;
    int left, right;
    for(i=num; i>=0;i--){ //starting at the bottom of the triangle
        for(j=i;j>=0;j--){ // starting from the right
            if(i<num){ // if we are at the second to last row and above
                left = triangle[i+1][j] + triangle[i][j]; // get left
                right = triangle[i+1][j+1] + triangle[i][j]; // get right
                if (left>right) // get larger between left and right
                {
                    triangle[i][j] = left;
                }else{
                    triangle[i][j] = right;
                }
            }				
        }
    }
    
    return triangle[0][0]; // return the top of the triangle, which now holds the best sume...
}