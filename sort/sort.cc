#include <iostream>
#include <vector>
#include <string>

void swap(int& a, int& b){
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void print(const std::string& tip, const std::vector<int>& nums){
  std::cout << tip;
  for(auto n:nums){
    std::cout << n <<" ";
  } 
  std::cout << std::endl;
}

//选择排序
//思路:每次排好最小的数。第一次遍历，用第一个数和后面所有的数比较,如果比第一个数小，交换；
//     第二次遍历,用第二个数和后面所有的数比较；以此类推...(selectionSort)
//优化：不用每次都做交换,记录最小的序号即可(selectionSort2)
void selectionSort(std::vector<int>& nums){
  if(nums.size()<2){
    return;
  }
  for(int i=0; i<nums.size()-1; ++i){
    for(int j=i+1; j<nums.size(); ++j){
      if(nums[i]>nums[j]){
        swap(nums[i], nums[j]);
      }
    }
  }
}

void selectionSort2(std::vector<int>& nums){
  if(nums.size()<2){
    return;
  }
  for(int i=0; i<nums.size()-1; ++i){
    int minIndex=i;
    for(int j=i+1; j<nums.size(); ++j){
      minIndex = nums[minIndex] < nums[j] ? minIndex:j;
    }
    swap(nums[i], nums[minIndex]);
  }
}

//冒泡排序
//思路:每次排好最大的数。外层循环表示每次排好第几个数,第一次排好最后一个数；
//     内层循环在这个范围内,做相邻两个的比较,大的往后交换。
void bobblesort(std::vector<int>& nums){
  if(nums.size()<2){
    return;
  }
  for(int i=nums.size()-1; i>0; --i){
    for(int j=0; j<i; ++j){
      if(nums[j]>nums[j+1]){
        swap(nums[j], nums[j+1]);
      }
    }
  }
}

//插入排序
//思路:将第n个数插入前面排好序的n-1个数。
//     第一次遍历,插nums[1];第二次遍历,插nums[2];以此类推...
//实现1:我自己想到的实现是先找到要插到哪里，再统一移动(insertionSort)
//      但实际上这样并不会像选择排序的优化一样，可以减少数据的交换，反而多写了一遍循环
//实现2:边比较边交换(insertionSort2),有点像冒泡，把小的往前冒
//实现3:和实现2思路一样，写法上更加简单：在循环中，满足某个条件才进行循环，可以把条件写在循环体中
void insertionSort(std::vector<int>& nums){
  if(nums.size()<2){
    return;
  }
  for(int i=1; i<nums.size(); ++i){
    int insertIndex=i;
    for(int j=i-1; j>=0; --j){
      if(nums[i] < nums[j]){
        insertIndex=j;
      }else{
        break;
      }
    }
    int tmp=nums[i];
    for(int k=i; k>insertIndex; --k){
      nums[k]=nums[k-1];
    }
    nums[insertIndex] = tmp;
  }
}

void insertionSort2(std::vector<int>& nums){
  if(nums.size()<2){
    return;
  }
  for(int i=1; i<nums.size(); ++i){
    for(int j=i; j>0; --j){
      if(nums[j] < nums[j-1]){
        swap(nums[j], nums[j-1]);
      }else{
        break;
      }
    }
  }
}

void insertionSort3(std::vector<int>& nums){
  if(nums.size()<2){
    return;
  }
  for(int i=1; i<nums.size(); ++i){
    for(int j=i; j>0, nums[j]<nums[j-1]; --j){
      swap(nums[j], nums[j-1]);
    }
  }
}

int main(){
  std::vector<int> nums{3, 2, 5, 4, 1};
  insertionSort3(nums);
  print("insert sort3 result: ",nums);
  return 0;
}
