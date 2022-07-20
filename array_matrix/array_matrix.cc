//题目1：转圈打印矩阵，要求额外空间复杂度为O(1)

//题目2：将正方形矩阵顺时针旋转90度，要求额外空间复杂度O(1)

//题目3：在行和列都排好序的数组中找数


#include <iostream>
#include <vector>

/*题目1解法
  给定左上角点和右下角点,一圈一圈打印。
  以
  1 2  3  4
  5 6  7  8
  9 10 11 12
  为例。
  第一次循环，给定左上角点(0,0) 右下角点(4,3),打印最外圈
  1 2  3  4
  5       8
  9 10 11 12
  第二次循环，左上角点(1,1) 右下角点(3,2)，打印第二圈
  6  7
  第三次循环，左下角点(2,2) 右下角点(2,1), 不存在，不再打印
*/
void spiralOrderPrint(const std::vector<std::vector<int>>& matrix){
  int x0 = 0;
  int y0 = 0;
  int x1 = matrix[0].size() - 1;
  int y1 = matrix.size() - 1;
  
  auto printEdge = [&](){
    if(y0 == y1){
      for(int i = x0; i <= x1; i++){
        std::cout << matrix[y0][i] << " ";
      }
    }else if(x0 == x1){
      for(int i = y0; i <= y1; i++){
        std::cout << matrix[i][x0] << " ";
      }
    }else{
      for (int i = x0; i <= x1; i++){
        std::cout << matrix[y0][i] << " ";
      }       
      for(int i = y0+1; i <= y1; i++){
        std::cout << matrix[i][x1] << " ";
      }
      for (int i = x1-1; i >= x0; i--){
        std::cout << matrix[y1][i] << " ";
      }       
      for(int i = y1-1; i >= y0+1; i--){
        std::cout << matrix[i][x0] << " ";
      }
    }
  };
  
  while(x0 <= x1 && y0 <= y1){
    printEdge();
    x0++;
    y0++;
    x1--;
    y1--; 
  }
  std::cout << std::endl;
}

/*题目2解法
  仍旧采用一圈一圈旋转的方式
*/
void rotate(std::vector<std::vector<int>>& matrix){
  int x0 = 0;
  int y0 = 0;
  int x1 = matrix[0].size() - 1;
  int y1 = matrix.size() - 1;

  auto rotateEdge = [&](){
    int times = x1 - x0;
    int tmp = 0;
    for(int i = 0; i != times; i++){
      tmp = matrix[y0][x0+i];
      matrix[y0][x0+i] = matrix[y1-i][x0];
      matrix[y1-i][x0] = matrix[y1][x1-i];
      matrix[y1][x1-i] = matrix[y0+i][x1];
      matrix[y0+i][x1] = tmp;
    }
  };

  while(x0 <= x1 && y0 <= y1){
    rotateEdge();
    x0++;
    y0++;
    x1--;
    y1--;
  }
}

void printMatrix(const std::vector<std::vector<int>>& matrix){
  for(auto vec : matrix){
    for(auto i : vec){
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

int main(){
  //题目1
  std::vector<std::vector<int>> matrix{
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13,14, 15, 16}
  };  
  printMatrix(matrix);
  spiralOrderPrint(matrix);
  //题目2
  rotate(matrix);
  printMatrix(matrix);
  return 0;
}
