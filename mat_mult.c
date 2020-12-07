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
void displayInv(float **result) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         printf("%f  ", result[i][j]);
         if (j == 3)
            printf("\n");
      }
   }
}

void display(int **result) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         printf("%d  ", result[i][j]);
         if (j == 3)
            printf("\n");
      }
   }
}

float determinant(float **m) 
{
   float det = 
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

float determinant3(float **m) 
{
   float det = 
      m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
      m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
      m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

   return (det);
}

float** transpose_matrix(float **buff)
{
    
    float **result = (float **)malloc(4 * sizeof(float *)); 
    for (int i = 0; i < 4; i++) 
         result[i] = (float *)malloc(4 * sizeof(float));
   //int buff[4][4] = {{-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8}};
   
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         result[i][j] = buff[j][i];
         //printf("Enter a%d%d: ", i + 1, j + 1);
         //scanf("%d", &result[i][j]);
      }
   }
   //display(result);
   return (result);
}

tuple mat_tuple(float **m, tuple t)
{
   tuple result;

   result.x = t.x * m[0][0] + t.y * m[0][1] + t.z * m[0][2] + t.w * m[0][3];
   result.y = t.x * m[1][0] + t.y * m[1][1] + t.z * m[1][2] + t.w * m[1][3];
   result.z = t.x * m[2][0] + t.y * m[2][1] + t.z * m[2][2] + t.w * m[2][3];
   result.w = t.x * m[3][0] + t.y * m[3][1] + t.z * m[3][2] + t.w * m[3][3];

   //printf("x: %f\n", result.x);
   //printf("y: %f\n", result.y);
   //printf("z: %f\n", result.z);
   //printf("w: %f\n", result.w);

   return (result);
}

tuple mat_tuple_float(float **m, tuple t)
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

float** init_matrix(float arr[16])
{
   int i;
   int j;
   int k;
   float **result;

   i = 0;
   j = 0;
   k = 0;
   result = (float **)malloc(4 * sizeof(float *));
   while (i < 4)
   {
      result[i] = (float *)malloc(4 * sizeof(float));
      i++;
   }    
   i = 0;
   while (i < 4)
   {
      while (j < 4)
      {      
         result[i][j] = arr[k];
         j++;
         k++;
      }
      j = 0;
      i++;
   }
   //displayInv(result);
   return (result);
}

float** identity_matrix()
{
   int i;
   int j;
   float **result;

   i = 0;
   j = 0;
   result = (float **)malloc(4 * sizeof(float *));
   while (i < 4)
   {
      result[i] = (float *)malloc(4 * sizeof(float));
      i++;
   }    
   i = 0;
   while (i < 4)
   {
      while (j < 4)
      {  
         if (i == j)
            result[i][j] = 1;
         else      
            result[i][j] = 0;
         j++;
      }
      j = 0;
      i++;
   }
   //displayInv(result);
   return (result);
}


/*int main() {
   int first[4][4], second[4][4], result[4][4];

   int buff[4][4] = {{-4,2,-2,-3}, {9,6,2,6}, {0,-5,1,-5}, {0,0,0,0}};
   //int buff1[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,8,7,6}, {5,4,3,2}};
   //int buff2[4][4] = {{-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8}};
   //int buff3[4][4] = {{8,-5,9,2}, {7,5,6,1}, {-6,0,9,6}, {-3,0,-9,-4}};
   //int buff3x3[3][3] = {{3,5,0}, {2,-1,-7}, {6,-1,5}};
   tuple t;

   t = point(0, 1, 0);

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
   //mat_tuple_float(rotation_x(M_PI / 4), t);

   //transpose matrix
   //transpose_matrix(buff);

   //determinant
   //printf("det: %d\n", determinant3(buff3x3));

   //subMatrix  Minor   Cofactor
   //minor3(buff3x3, 1, 0);
   //cofactor3(buff3x3, 1, 0);

   //Inverse
   //inverse(buff1);

   //translation
   //translation(4, 1, 2);

   //scaling
   //scaling(1, 2, 3);

   //rotation
   //rotation_z(0.45 * M_PI);

   //shearing
   /*t_shear s;
   s.x_y = 0;
   s.x_z = 0;
   s.y_x = 0;
   s.y_z = 0;
   s.z_x = 0;
   s.z_y = 1;

   shearing(s);


   return 0;
}*/
