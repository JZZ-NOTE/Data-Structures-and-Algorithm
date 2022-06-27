#include <iostream>

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

int main(){
  std::cout << "输入n: ";
  int n;
  std::cin >> n;
  std::cout << n << "的阶乘为: " << jiecheng0(n) << ", " << jiecheng(n) << std::endl;
}


