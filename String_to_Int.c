#include <iostream>
#include <string>
using namespace std;
// 67:把字符串转换成整数
class Solution {
public:
    /*全局变量*/
    enum {kValid,kInvalid}; // 枚举元素（kValid=0，kInvalid=1）
    int g_nStatus = kValid; // 标记是否是非法输入

    /*功能函数*/
    int StrToInt(string str)
    {
        g_nStatus = kInvalid;          // 初始标记为非法输入
        long long num = 0;             // 存储结果
        const char* cstr = str.c_str();// 指向字符数组的指针

        // 判断是否是空指针和空字符串""
        if( (cstr != NULL) && (*cstr != '\0') )
        {
            // 处理符号位
            int minus = 1;
            if(*cstr == '-')
            {
                minus = -1;
                cstr++;
            }
            else if(*cstr == '+')
            {
                minus = 1;
                cstr++;
            }

            // 处理其余位
            while(*cstr != '\0')
            {
                if(*cstr > '0' && *cstr < '9')
                {
                    // string转int类型
                    g_nStatus = kValid;           // 标记为合法输入
                    num = num*10 + (*cstr -'0');  // string转换为int类型
                    cstr++;

                    // 数据上下溢出
                    if( ((minus>0) && (num > 0x7FFFFFFF)) ||((minus<0) && (num > 0x80000000)) )
                    {
                        g_nStatus = kInvalid; // 如果溢出，则标记为非法输入
                        num = 0;
                        break;
                    }
                }
                else
                {
                    g_nStatus = kInvalid;
                    num = 0;
                    break;
                }
            }

            if(g_nStatus == kValid)
                num = num * minus;

        }
        cout<<(int)num<<endl;
        return (int)num;
    }
};
int main()
{
    string str = "123";
    Solution solution;
    solution.StrToInt(str);
    return 0;
}

