#include <iostream>
#include <vector>
#include <stack>

//题目1：使用数组实现固定大小的队列和栈，例如大小为 6

//题目2：实现一个特殊的栈，在实现栈的基础上，可返回栈内最小值。要求 pop、push、getMin 操作的时间复杂度都是O(1)
class mystack{
public:
  void push(int x){
    stack_.push(x);
    if(min_stack_.empty()){
      min_stack_.push(x);
    }else{
      x = x < min_stack_.top() ? x:min_stack_.top();
      min_stack_.push(x); 
    }
  }

  void pop(){
    min_stack_.pop();
    stack_.pop();
  }

  int getMin(){
    return min_stack_.top();
  }
private:
  std::stack<int> stack_;
  std::stack<int> min_stack_;
};

//题目3：使用队列结构实现栈结构；使用栈结构实现队列结构

int main(){
  mystack s;
  s.push(2);
  std::cout << s.getMin() << std::endl;
  s.push(3);
  std::cout << s.getMin() << std::endl;
  s.push(1);
  std::cout << s.getMin() << std::endl;
  s.pop();
  std::cout << s.getMin() << std::endl;
}
