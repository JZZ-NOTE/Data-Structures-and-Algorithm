#include <iostream>
#include <vector>

/*暴力递归
* 1.把问题转化为规模缩小了的同类问题的子问题
* 2.有明确的不需要进行递归的条件
* 3.有当得到了子问题的结果之后的决策过程
* 4.不记录每一个子问题的解
*/

/*动态规划
* 1.从暴力递归中来
* 2.将每一个子问题的解记录下来，避免重复计算
* 3.把暴力递归的过程，抽象成了状态表达
* 4.存在化简状态表达，使其更加简洁的可能
*/

//举例1：求 n! 的结果
//非递归版本：我知道怎么算，直接算就可以了
int jiecheng0(int n){
  int result = 1;
  for (int i=1; i<=n; i++){
    result *= i;
  }
  return result;
}
//递归版本: 我不知道该怎么办，但如果我知道 n-1 怎么算，我就会算了
int jiecheng(int n){
  if(n==1){
    return 1;
  }
  return n*jiecheng(n-1);
}
//联系：非递归版本可以看做递归版本的逆过程

//举例二：汉诺塔问题，打印 n 层汉诺塔从最左边移动到最右边的过程
// from to help
// 把 1-n 从 from 移动到 to
// 第一步：1~n-1 from~help
// 第二步：n     from~to
// 第三步：1~n-1 help~to
void func(int rest, int down, std::string from, std::string help, std::string to){
  if (rest == 1){
    std::cout << "move " << down << "from " << from << "to " << to << std::endl;
  } else {
    func(rest-1, down-1, from, to, help);
    func(1, down, from, help, to);
    func(rest-1, down-1, help, from, to);
  }
}

//举例三：打印一个字符串的全部子序列，包括空字符串

//举例四：背包问题，正数数组中是否存在和为 aim 的组合
bool isSum(const std::vector<int>& nums, int i, int sum, int aim){
  if(i == nums.size()){
    return sum == aim;
  }
  return isSum(nums, i+1, sum, aim) || isSum(nums, i+1, sum+nums[i], aim);
}

///斐波那契数列 1 1 2 3 5 8 13 21... 从第3个数开始，F(n)=F(n-1)+F(n-2)
//递归实现，时间复杂度 O(2^n) 时间复杂度可百度
int FeiBoNaQi(int n){
  if(n<3){
    return 1;
  }
  return FeiBoNaQi(n-1)+FeiBoNaQi(n-2);
}
//动态规划实现，时间复杂度 O(n)
int FeiBoNaQi2(int n){
  if(n<3){
    return 1;
  }
  std::vector<int> nums(n+1,0);
  nums[1] = 1;
  nums[2] = 1;
  for(int i=3; i<=n; i++){
    nums[i] = nums[i-1] + nums[i-2];
  }
  return nums[n];
}
//动态规划实现2，时间复杂度 O(n)，空间上不再维护数组，因为 F(n) 只与 F(n-1) 与 F(n-2) 有关，只需要记下这两个数
int FeiBoNaQi3(int n){
  if(n<3){
    return 1;
  }
  int pre1 = 1; 
  int pre2 = 1;
  int res = 0;
  for (int i=3; i<=n; i++){
    res = pre1 + pre2;
    pre2 = pre1;
    pre1 = res;
  }
  return res;
}

///上台阶问题：上台阶，每次可上1阶或2阶，问上n阶有多少种方法。F(1)=1,F(2)=2,F(n)=F(n-1)+F(n-2)
///母牛生小牛问题：初始有1只成熟母牛，第二年开始生小母牛，小母牛3年后成熟可生1只小母牛，问 n 年后有多少只母牛。1 2 3 4 6 9... F(n)=F(n-1)+F(n-3)

int main(){
  std::cout << "输入n: ";
  int n;
  std::cin >> n;
  std::cout << n << "的阶乘为: " << jiecheng0(n) << ", " << jiecheng(n) << std::endl;

  std::cout << "是否和为 aim: ";
  std::vector<int> nums{3, 2, 7, 13};
  int aim = 9;
  std::cout << isSum(nums, 0, 0, aim) << std::endl;

  std::cout << "输入n(第n个斐波那契数)：";
  int num;
  std::cin >> num;
  std::cout << FeiBoNaQi(num) << " " << FeiBoNaQi2(num) << " " << FeiBoNaQi3(num) << std::endl;
}
