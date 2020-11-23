#include "header.h"

// function to get matrix elements entered by the user
void getMatrixElements1(int matrix[][4], int buff[][4])
{

   //int buff[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,8,7,6}, {5,4,3,2}};
   
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         matrix[i][j] = buff[i][j];
         //printf("Enter a%d%d: ", i + 1, j + 1);
         //scanf("%d", &matrix[i][j]);
      }
   }
}

void getMatrixElements2(int matrix[][4], int buff[][4])
{

   //int buff[4][4] = {{-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8}};
   
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         matrix[i][j] = buff[i][j];
         //printf("Enter a%d%d: ", i + 1, j + 1);
         //scanf("%d", &matrix[i][j]);
      }
   }
}

// function to display the matrix
void display(int result[][4]) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         printf("%d  ", result[i][j]);
         if (j == 3)
            printf("\n");
      }
   }
}

int determinant(int m[][4]) 
{
   int det = 
      m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
      m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
      m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
      m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
      m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
      m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
      m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
      m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
      m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
      m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
      m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
      m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];

   return (det);
}

Mat transpose_matrix(int buff[][4])
{

   int matrix[4][4];
   //int buff[4][4] = {{-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8}};
   
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         matrix[i][j] = buff[j][i];
         //printf("Enter a%d%d: ", i + 1, j + 1);
         //scanf("%d", &matrix[i][j]);
      }
   }
   display(matrix);
   return (matrix);
}

tuple mat_tuple(int m[][4], tuple t)
{
   tuple result;

   result.x = t.x * m[0][0] + t.y * m[0][1] + t.z * m[0][2] + t.w * m[0][3];
   result.y = t.x * m[1][0] + t.y * m[1][1] + t.z * m[1][2] + t.w * m[1][3];
   result.z = t.x * m[2][0] + t.y * m[2][1] + t.z * m[2][2] + t.w * m[2][3];
   result.w = t.x * m[3][0] + t.y * m[3][1] + t.z * m[3][2] + t.w * m[3][3];

   printf("x: %f\n", result.x);
   printf("y: %f\n", result.y);
   printf("z: %f\n", result.z);
   printf("w: %f\n", result.w);

   return (result);
}

// function to multiply two matrices
Mat multiplyMatrices(int first[][4],
                      int second[][4],
                      int result[][4]) {

   // Initializing elements of matrix mult to 0.
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         result[i][j] = 0;
      }
   }

   // Multiplying first and second matrices and storing it in result
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         for (int k = 0; k < 4; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
   return (result);
}

Mat multiply_identity(int mat[][4])
{
   int identity[4][4] = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}};
   int result[4][4];
   return (multiplyMatrices(mat, identity, result));
}



int main() {
   int first[4][4], second[4][4], result[4][4];
   /*printf("Enter rows and column for the first matrix: ");
   scanf("%d %d", &r1, &c1);
   printf("Enter rows and column for the second matrix: ");
   scanf("%d %d", &r2, &c2);

   // Taking input until
   // 1st matrix columns is not equal to 2nd matrix row
   while (c1 != r2) {
      printf("Error! Enter rows and columns again.\n");
      printf("Enter rows and columns for the first matrix: ");
      scanf("%d%d", &r1, &c1);
      printf("Enter rows and columns for the second matrix: ");
      scanf("%d%d", &r2, &c2);
   }*/

   int buff[4][4] = {{1,2,3,4}, {2,4,4,2}, {8,6,4,1}, {0,0,0,1}};
   int buff1[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,8,7,6}, {5,4,3,2}};
   int buff2[4][4] = {{-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8}};
   int buff3[4][4] = {{-6,1,1,6}, {-8,5,8,6}, {-1,0,8,2}, {-7,1,-1,1}};
   int buff3x3[3][3] = {{3,5,0}, {2,-1,-7}, {6,-1,5}};
   tuple t;

   t = point(1, 2, 3);

   // get elements of the first matrix
   //getMatrixElements1(first, buff1);

   // get elements of the second matrix
   //getMatrixElements2(second, buff2);

   // multiply two matrices.
   //multiplyMatrices(first, second, result);

   //multiply_identity(buff);

   // display the result
   //display(result);

   //multiply by a tuple
   //mat_tuple(buff, t);

   //transpose matrix
   //transpose_matrix(buff);

   //determinant
   //determinant(buff);

   //subMatrix
   minor3(buff3x3, 1, 0);

   return 0;
}
