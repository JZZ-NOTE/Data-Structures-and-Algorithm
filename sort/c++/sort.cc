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

//冒泡排序
//思路1：每次排好最小的数。第一次遍历，用第一个数和后面所有的数比较；
//      第二次遍历，用第二个数和后面所有的数比较；以此类推...
//思路2：每次排好最大的数。外层循环表示每次排好第几个数，第一次排好最后一个数；
//      内层循环在这个范围内，做相邻两个的比较，大的往后交换。
void bullesort(std::vector<int>& nums){
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

void bullesort2(std::vector<int>& nums){
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

int main(){
  std::vector<int> nums{3, 2, 5, 4, 1};
  bullesort2(nums);
  print("bull sort result: ",nums);
  return 0;
}
