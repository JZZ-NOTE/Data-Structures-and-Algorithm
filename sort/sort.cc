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
//时间复杂度 O(n^2),额外空间复杂度 O(1)：有限的几个变量就可以
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

//归并排序
//归并排序是递归过程，递归相关的信息，可查看 递归 目录
//思路:数组一半一半去排好，再合并两个排好序的数组
//时间复杂度：O(n*logn),额外空间复杂度O(N)
//实现1(mergeSort1)和实现2(mergeSort2)的区别在与 实现2不需要返回一个临时数组，在原来的nums上排好，更简洁
//实现3是教程实现，和实现2的差别仅在于遍历形式
std::vector<int> mergeSort(std::vector<int>& nums, int l, int r){
  if(l==r){
    return std::vector<int>{nums[l]};
  }
  int mid = l/2 + r/2;
  std::vector<int> l_nums = mergeSort(nums, l, mid);
  std::vector<int> r_nums = mergeSort(nums, mid+1, r);
  std::vector<int> result(r-l+1);
  int p_l = 0;
  int p_r = 0;
  for(int i=0; i<r-l+1; ++i){
    if(p_l>=l_nums.size()){
      result[i] = r_nums[p_r++];
    }else if(p_r>=r_nums.size()){
      result[i] = l_nums[p_l++];
    }else{
      result[i] = l_nums[p_l] < r_nums[p_r] ? l_nums[p_l++]:r_nums[p_r++];
    }
  }  

  return result;
}

void  mergeSort2(std::vector<int>& nums, int l, int r){
  if(l==r){
    return; 
  }
  int mid = l/2 + r/2;
  mergeSort2(nums, l, mid);
  mergeSort2(nums, mid+1, r);
  std::vector<int> result(r-l+1);
  int p_l = l;
  int p_r = mid+1;
  for(int i=0; i<r-l+1; ++i){
    if(p_l>mid){
      result[i] = nums[p_r++];
    }else if(p_r>r){
      result[i] = nums[p_l++];
    }else{
      result[i] = nums[p_l] < nums[p_r] ? nums[p_l++]:nums[p_r++];
    }
  }  
  for(int i=0; i<r-l+1; ++i){
    nums[l+i] = result[i];
  }
}

void  mergeSort3(std::vector<int>& nums, int l, int r){
  if(l==r){
    return; 
  }
  int mid = l/2 + r/2;
  mergeSort3(nums, l, mid);
  mergeSort3(nums, mid+1, r);
  std::vector<int> result(r-l+1);
  int p_l = l;
  int p_r = mid+1;
  int i = 0;
  while(p_l<=mid && p_r<=r){
    result[i++] = nums[p_l] < nums[p_r] ? nums[p_l++]:nums[p_r++];
  }  
  while(p_l<=mid){
    result[i++] = nums[p_l++];
  }
  while(p_r<=r){
    result[i++] = nums[p_r++];
  } 

  for(int i=0; i<r-l+1; ++i){
    nums[l+i] = result[i];
  }
}

//小和问题：给一个数组，每个数之前比它小的数求和
//举例：1 3 4 2 5
//3: 1
//4: 1、3
//2：1
//5：1、3、4、2
//和：1+1+3+1+1+3+4+2=16
//思路1：最直接的思路就是遍历，把每个数和它之前所有的数进行比较，时间复杂度 O(n^2)
//思路2：每个数找它前面离他最近的比它小的数，那么它的小和就是在这个数的小和基础上，加上这个数自己，时间复杂度和数组的排列有关，如果数组是从大到小排的话，还是 O(n^2)
//思路3：分治，归并排序的思路，在合并的时候作手脚
//先写一个归并排序
void littleSum(std::vector<int>& nums, int l, int r, int& sum){
  if(l==r){
    return;  
  }
  int mid = l/2 + r/2;
  littleSum(nums, l, mid, sum);
  littleSum(nums, mid+1, r, sum);
  std::vector<int> result(r-l+1);
  int p_l = l;
  int p_r = mid+1;
  int i = 0;
  while(p_l<=mid && p_r<=r){
    //if(nums[p_l]<nums[p_r]){
    //  sum += (r-p_r+1)*nums[p_l];
    //}
    sum += nums[p_l]<nums[p_r]? (r-p_r+1)*nums[p_l]:0;
    result[i++] = nums[p_l]<nums[p_r]? nums[p_l++]:nums[p_r++];
  }
  while(p_l<=mid){
    result[i++] = nums[p_l++];
  }
  while(p_r<=r){
    result[i++] = nums[p_r++];
  }
  for(int i=0; i<r-l+1; ++i){
    nums[l+i] = result[i];
  }
}      

//逆序对问题：一个数组中，左边的数如果比右边的数大，两个数构成一个逆序对，打印所有逆序对
//和小和问题同理,从大到小排数组

//归并排序为什么快，因为我比较之后的一些信息被用到了
//1,3,5 / 2,4,6
//当我知道1比2小的时候，我就知道1比2之后的数都小了，不需要再进行比较了
 
//快速排序热身1：
//要求1：给定一个数组nums，和一个数num，请把小于等于num的数放在数组的左边，大于num的数放在数组的右边
//要求2：给定一个数组nums，和一个数num，请把小于num的数放在数组的左边，大于num的数放在数组的右边,等于 num 的数放在中间
//要求额外空间复杂度O(1),时间复杂度O(n)
//实现一：自己写的，实现了要求1，要求2实现有点难
void partition1(std::vector<int>& nums, int num){
  int l = 0;
  int r = nums.size()-1;
  while(l<r){
    while(nums[l] < num){
      l++;
    }
    while(nums[r] > num){
      r--;
    }
    swap(nums[l++], nums[r--]);
  }
}
//实现2：教程实现
//遍历数组的过程中，修改 l 和 r 的位置。l 和 r 是小于等于大于num的分界线
//这里重点要理解的是什么时候 遍历的序号要++
//和 l 后面的数交换之后++，因为 l 后面的数和我当前操作的数中间的数，一定是等于 num 的
//和 r 前面的数交换之后不++，因为交换来的数是不确定的，还需要再判断。
void partition2(std::vector<int>& nums, int num){
  int l = -1;
  int r = nums.size();
  int i = 0;
  while(i<r){
    if(nums[i]<num){
      swap(nums[i++], nums[++l]); 
    }else if(nums[i]>num){
      swap(nums[i], nums[--r]);   
    }else{
      i++;
    }
  }
}


//快速排序就是上面的思路
//选择一个数x，把数组分成两部分，小于等于x的放左边，大于x的放左边
//再分成的两份中继续这样做，最后就有序了
//每次用右边界作为这个选择的数
//时间复杂度O(n*logn),额外空间复杂度O(logn)——标记点
std::pair<int, int> partition(std::vector<int>& nums, int l, int r, int num){
  int p_l = l-1;
  int p_r = r+1;
  int p_cur = l;
  while(p_cur<p_r){
    if(nums[p_cur]<num){
      swap(nums[p_cur++], nums[++p_l]);
    }else if(nums[p_cur]>num){
      swap(nums[p_cur], nums[--p_r]);
    }else{
      p_cur++;
    }
  }
  return std::pair<int,int>(p_l,p_r);
}

void quickSort(std::vector<int>& nums, int l, int r){
  //这里的r可能为-1，原因是如果第一次选中一个最小值，那么原来的数组就会被划分为 0,-1 / 1,4
  if(l>=r){
    return;
  }
  //这里可以随机选择一个数和 nums[r] 交换  
  std::pair<int, int> p = partition(nums, l, r, nums[r]);
  quickSort(nums, l, p.first);
  quickSort(nums, p.second, r);
}

//堆排序
//堆是一棵完全二叉树
//堆可以用数组表示
//大根堆、小根堆
//函数1：把一个数组变成大根堆,假设 index 之前的部分已经变成大根堆，现在把 nums[index] 放进来，让数组还是大根堆
//思路是把一个数和父节点比较，往上浮
void heapInsert(std::vector<int>& nums, int index){
  //index>0，可以不判断，因为 -1/2 也是0，nums[0]=nums[0]
  while(index>0 && nums[index]>nums[(index-1)/2]){
    swap(nums[index], nums[(index-1)/2]);
    index = (index-1)/2;
  }
}

//函数2：大根堆中某个数字发生改变，重新调整数组为大根堆
//思路是把一个数和子节点比较，往下沉
void heapify(std::vector<int>& nums, int index, int heapsize){
  int left = index*2+1;
  while(left<heapsize){
    //左右节点哪个大
    int largest = left+1<heapsize && nums[left+1]>nums[left] ? left+1:left;
    //左右节点的大值和当前节点哪个大
    largest = nums[largest]>nums[index] ? largest:index;    
    
    if(largest==index){
      break;
    }    

    swap(nums[largest], nums[index]);
    index = largest;
    left = index*2+1;    
  }
}

void heapSort(std::vector<int>& nums){
  if(nums.size()<2){
    return; 
  }
  //把数组变成大根堆,复杂度 O(N)=log1+log2+...+logN
  for(int i=0; i<nums.size(); ++i){
    heapInsert(nums, i);
  }
  //依次取出最大值放到数组最后
  int heapsize = nums.size()-1;
  swap(nums[0],nums[heapsize]);
  while(heapsize>0){
    heapify(nums, 0, heapsize);
    swap(nums[0],nums[--heapsize]);
  }
}

//桶排序、计数排序、基数排序
//非基于比较的排序
//例如：已知数组中所有数字都在 0-60 之间，对数组中的数据排序
//桶排序：按照数据状况，把排序对象放入不同的容器中；计数排序是桶排序的一种。
//基数排序：个位、十位、百位
//应用一：给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度O(N)，不能使用基于比较的排序。


int main(){
  std::vector<int> nums{3, 2, 5, 4, 1};
  print("nums: ", nums);

  //insertionSort3(nums);
  //print("insert sort3 result: ", nums);

  //归并排序1
  //std::vector<int> result;
  //result = mergeSort1(nums, 0, nums.size()-1);
  //print("merge sort1 result: ", result);

  //归并排序2
  //mergeSort2(nums, 0, nums.size()-1);
  //print("merge sort3 result: ", nums);

  //归并排序3
  //mergeSort3(nums, 0, nums.size()-1);
  //print("merge sort3 result: ", nums);
  
  //小和问题
  //int sum = 0;
  //littleSum(nums, 0, nums.size()-1, sum);
  //std::cout << "little sum is: " << sum << std::endl;
   
  //快速排序热身1
  //partition2(nums, 3);
  //print("quick sort prepare1: ", nums);
  
  //快速排序
  //quickSort(nums, 0, nums.size()-1);
  //print("quick sort result: ", nums);

  //堆排序
  heapSort(nums);
  print("heap sort result: ", nums);
  return 0;
}
