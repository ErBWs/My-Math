/*
 * @file    my_math.c
 * @author  ErBW_s
 * @date    2022/04/19
 */

#include "my_math.h"


/*
 * @brief       最小二乘法
 * @param       data[][]        求直线的数组
 * @param       count           数组长度
 * @param       status          1:输出k; 2:输出b
 * @return      k / b
 */
float Ordinary_Least_Squares(float data[][2], int count, int status)
{
    int i = 0;
    float sumX = 0;
    float sumY = 0;
    float averageX = 0;
    float averageY = 0;
    float sumUp = 0;    //系数k公式的分子
    float sumDown = 0;  //系数k公式的分母
    float k;
    float b;    //y=kx+b

    //get average of X & Y
    while (i < count - 1)
    {
        sumX += data[i][1];
        sumY += data[i][0];
        i++;
    }
    averageX = sumX / count;
    averageY = sumY / count;

    // k
    do
    {
        sumUp += (data[i][0] - averageY) * (data[i][1] - averageX);
        sumDown += (data[i][1] - averageX) * (data[i][1] - averageX);
    } while (--i >= 0);
    if (sumDown == 0)    //防止分母为0
    {
        k = 0;
    } else
    {
        k = sumUp / sumDown;
    }

    // b
    b = averageY - k * averageX;

    // Output
    switch (status)
    {
        case 1:
            return k;
        case 2:
            return b;
    }
}


/*
 * @brief       二分查找法
 * @param       arr     二分查找的数组
 * @param       l       一般直接输入1即可
 * @param       r       数组长度
 * @param       val     二分查找的对象
 * @return      mid     数组下标
 */
int Binary_Search(int *arr, int l, int r, int val)
{
    while (l <= r)
    {
        // Divide by 2
        int mid = (l + r) >> 1;

        // Find target
        if (val == *(arr + mid))
        {
            return mid;
        } else if (val > *(arr + mid))
        {
            l = mid + 1;
        } else
        {
            r = mid - 1;
        }
    }
    return -1;
}