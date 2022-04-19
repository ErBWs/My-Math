/*
 * @file    my_math.c
 * @author  ErBW_s
 * @date    2022/04/19
 */

#include "my_math.h"


/*
 * @brief       ��С���˷�
 * @param       data[][]        ��ֱ�ߵ�����
 * @param       count           ���鳤��
 * @param       status          1:���k; 2:���b
 * @return      k / b
 */
float Ordinary_Least_Squares(float data[][2], int count, int status)
{
    int i = 0;
    float sumX = 0;
    float sumY = 0;
    float averageX = 0;
    float averageY = 0;
    float sumUp = 0;    //ϵ��k��ʽ�ķ���
    float sumDown = 0;  //ϵ��k��ʽ�ķ�ĸ
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
    if (sumDown == 0)    //��ֹ��ĸΪ0
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
 * @brief       ���ֲ��ҷ�
 * @param       arr     ���ֲ��ҵ�����
 * @param       l       һ��ֱ������1����
 * @param       r       ���鳤��
 * @param       val     ���ֲ��ҵĶ���
 * @return      mid     �����±�
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