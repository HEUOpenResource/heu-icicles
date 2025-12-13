#include <stdio.h>

// 寻找不共有的元素
void findUniqueElements(int arr1[], int n1, int arr2[], int n2)
{
    int unique[40]; // 存储不是两个数组共有的元素
    int count = 0;  // 计数器

    // 检查第一个数组中的元素
    for (int i = 0; i < n1; i++)
    {
        int found = 0;

        // 检查第一个数组中的元素是否在第二个数组中出现过
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                found = 1;
                break;
            }
        }

        // 如果第一个数组的元素不在第二个数组中，存储起来
        if (!found)
        {
            int duplicate = 0;

            // 检查是否已经存储过该元素
            for (int k = 0; k < count; k++)
            {
                if (unique[k] == arr1[i])
                {
                    duplicate = 1;
                    break;
                }
            }

            // 如果不是重复元素，则存储
            if (!duplicate)
            {
                unique[count++] = arr1[i];
            }
        }
    }

    // 检查第二个数组中的元素
    for (int i = 0; i < n2; i++)
    {
        int found = 0;

        // 检查第二个数组中的元素是否在第一个数组中出现过
        for (int j = 0; j < n1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                found = 1;
                break;
            }
        }

        // 如果第二个数组的元素不在第一个数组中，存储起来
        if (!found)
        {
            int duplicate = 0;

            // 检查是否已经存储过该元素
            for (int k = 0; k < count; k++)
            {
                if (unique[k] == arr2[i])
                {
                    duplicate = 1;
                    break;
                }
            }

            // 如果不是重复元素，则存储
            if (!duplicate)
            {
                unique[count++] = arr2[i];
            }
        }
    }

    // 输出结果
    for (int i = 0; i < count; i++)
    {
        printf("%d ", unique[i]);
    }
}

int main()
{
    int n1, n2;
    int arr1[20], arr2[20];

    // 读取第一个数组
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // 读取第二个数组
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // 调用函数找出不是两个数组共有的元素
    findUniqueElements(arr1, n1, arr2, n2);

    return 0;
}