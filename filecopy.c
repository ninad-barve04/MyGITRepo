int find_in_matrix(int search, int **matrix, int nrow, int ncol) {
    int found = 0;
    for (int i = 0; i < nrow; i++) {
        if (search >= matrix[i][0] && search <= matrix[i][ncol-1]) {
            //number is found in 'i'th row
            for (int j = 0; j < ncol; j++) {
                if (search == matrix[i][j]) {
                    printf("Number found at row %d, col %d\n", i, j);
                    found = 1;
                    break;
                } else if (search < matrix[i][j]) {
                    found = 0;
                    break;
                }
            }
        } else if (search < matrix[i][ncol-1]) {
            found = 0;
            break;
        }
    }
    return found;
}

