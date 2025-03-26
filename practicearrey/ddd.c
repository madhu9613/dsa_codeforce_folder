// #include <stdio.h>

// #define MAX 100  // Maximum number of nonzero elements

// // Structure for sparse matrix elements
// struct Element {
//     int row, col, value;
// };

// // Function to perform fast transpose of a sparse matrix
// void fastTranspose(struct Element A[], struct Element T[]) {
//     int numCols = A[0].col, numTerms = A[0].value;
//     int count[MAX] = {0}, position[MAX];

//     T[0].row = A[0].col;
//     T[0].col = A[0].row;
//     T[0].value = numTerms;

//     // Step 1: Count occurrences of each column
//     for (int i = 1; i <= numTerms; i++) {
//         count[A[i].col]++;
//     }

//     // Step 2: Compute starting position for each column in transposed matrix
//     position[0] = 1;
//     for (int i = 1; i < numCols; i++) {
//         position[i] = position[i - 1] + count[i - 1];
//     }

//     // Step 3: Place elements in their correct positions
//     for (int i = 1; i <= numTerms; i++) {
//         int col = A[i].col;
//         int pos = position[col]++;
//         T[pos].row = A[i].col;
//         T[pos].col = A[i].row;
//         T[pos].value = A[i].value;
//     }
// }

// // Function to read a sparse matrix
// void inputSparseMatrix(struct Element sparse[]) {
//     int rows, cols, nonZero;
//     printf("Enter number of rows and columns: ");
//     scanf("%d %d", &rows, &cols);
//     printf("Enter number of nonzero elements: ");
//     scanf("%d", &nonZero);

//     sparse[0].row = rows;
//     sparse[0].col = cols;
//     sparse[0].value = nonZero;

//     printf("Enter nonzero elements (row col value):\n");
//     for (int i = 1; i <= nonZero; i++) {
//         scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
//     }
// }

// // Function to print a sparse matrix
// void printSparseMatrix(struct Element sparse[]) {
//     for (int i = 0; i <= sparse[0].value; i++) {
//         printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
//     }
// }

// int main() {
//     struct Element A[MAX], T[MAX];

//     printf("Input Matrix A:\n");
//     inputSparseMatrix(A);

//     printf("\nOriginal Sparse Matrix:\n");
//     printSparseMatrix(A);

//     fastTranspose(A, T);

//     printf("\nTransposed Sparse Matrix (Fast Transpose):\n");
//     printSparseMatrix(T);

//     return 0;
// }


// #include <stdio.h>

// #define MAX 100  // Maximum nonzero elements

// // Structure to store sparse matrix elements
// struct Element {
//     int row, col, value;
// };

// // Function to perform naive transpose of a sparse matrix
// void naiveTranspose(struct Element A[], struct Element T[]) {
//     int numTerms = A[0].value;

//     // Copy metadata
//     T[0].row = A[0].col;
//     T[0].col = A[0].row;
//     T[0].value = numTerms;

//     int k = 1;
//     for (int i = 0; i < A[0].col; i++) {
//         for (int j = 1; j <= numTerms; j++) {
//             if (A[j].col == i) {  // Find elements of the same column
//                 T[k].row = A[j].col;
//                 T[k].col = A[j].row;
//                 T[k].value = A[j].value;
//                 k++;
//             }
//         }
//     }
// }

// // Function to read a sparse matrix
// void inputSparseMatrix(struct Element sparse[]) {
//     int rows, cols, nonZero;
//     printf("Enter number of rows and columns: ");
//     scanf("%d %d", &rows, &cols);
//     printf("Enter number of nonzero elements: ");
//     scanf("%d", &nonZero);

//     sparse[0].row = rows;
//     sparse[0].col = cols;
//     sparse[0].value = nonZero;

//     printf("Enter nonzero elements (row col value):\n");
//     for (int i = 1; i <= nonZero; i++) {
//         scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
//     }
// }

// // Function to print a sparse matrix
// void printSparseMatrix(struct Element sparse[]) {
//     for (int i = 0; i <= sparse[0].value; i++) {
//         printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
//     }
// }

// int main() {
//     struct Element A[MAX], T[MAX];

//     printf("Input Matrix A:\n");
//     inputSparseMatrix(A);

//     printf("\nOriginal Sparse Matrix:\n");
//     printSparseMatrix(A);

//     naiveTranspose(A, T);

//     printf("\nTransposed Sparse Matrix:\n");
//     printSparseMatrix(T);

//     return 0;
// }