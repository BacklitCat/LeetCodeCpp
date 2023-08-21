#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0); // 似乎可不写
    // IO
}

// https://blog.csdn.net/qq_40794973/article/details/83795025
// https://blog.csdn.net/weixin_45525272/article/details/114055623
//
/*
这俩一个输入同步，一个输出同步
sync_with_stdio是输入同步开关
cin.tie是控制输出同步
用哪个关哪个

注意，这两个代码的头文件是 iostream
并且如果用了这两个，就不要用scanf ,getchar,gets,fgets,fscanf了。
好处：将cin cout速度提升至与scanf相差无几。
副作用：不能scanf cin之类的混用了。
 */