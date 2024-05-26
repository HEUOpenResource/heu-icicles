/*
@Filename: ex607.c
@Author: Ju Chengdong
@Version: 1.0
@Date: 2021-03-18
@Description: Two Dimensional Dynamic Array
*/

#include<stdio.h>
#include<stdlib.h>

/*
 * 动态申请二维数组的方法： 
 * 方法一：利用一个二级指针来实现（本例所采用的方法） 
 * 方法二：利用数组指针来实现
 * 方法三：利用一维数组来模拟二维数组 
 */

/*
 * 1. 动态数组的创建和引用应遵循原则：
 * （1）申请的时候从外层往里层，逐层申请；
 * （2）释放的时候从里层往外层，逐层释放。
 * 2. 构建动态数组时所需指针：
 * （1）对于构建一维动态数组，需要一维指针；
 * （2）对于构建二维动态数组，需要一维、二维指针；
 * （3）对于构建三维动态数组，需要一维、二维、三维指针；
 * （4）依此类推。
 * 3. 构建动态数组时所需函数：
 * （1）malloc()
 * （2）calloc()
 * （3）free()
 * （4）realloc()等
 * 4. 使用malloc()函数创建一维动态数组的一般格式：
 *    类型说明符 *数组名 = (类型说明符 *)malloc(数组长度 * sizeof(类型说明符));
 * 5. 使用malloc()函数创建二维动态数组的一般格式：
 *    类型说明符 **数组名 = (类型说明符 **)malloc(第一维长度 * sizeof(类型说明符*));
 *    示例：
 *    int **arr=(int **)malloc(n1*sizeof(int *));
 *    for(i=0;i<第一维长度;i++){
 *        数组名[i] = (类型说明符 *)malloc(第二维长度 * sizeof(类型说明符));
 *    } 
 */

int main(void){
	void assignValuesTo2DArray(int **arr, int rows, int columns);
	void show2DArray(int **arr, int rows, int columns);
	int **create2DArray(int rows, int columns);
	void free2DArray(int **array, int rows);
	
	/*输入二维动态数组的行数和列数*/
	int rows,columns;
	scanf("%d,%d", &rows, &columns);
	
	/*创建二维动态数组*/
	int **array = create2DArray(rows, columns);
	if(array != NULL){/*若创建成功*/
		/*为二维动态数组元素赋值*/
		assignValuesTo2DArray(array, rows, columns);
		/*屏显二维动态数组元素值*/
		show2DArray(array, rows, columns);
	}
	/*释放二维动态数组的内存空间*/
	free2DArray(array, rows);
	
	return 0;
}

/*
 * 函数名称：assignValuesTo2DArray
 * 函数功能：为形参arr所指向的二维数组的元素赋值，赋值公式为： 
 *           arr[i][j]=i*columns+j+1
 * 形式参数：arr为指向int型二维数组首地址的指针的指针；
 *           rows为二维数组的行数（第一维长度）；
 *           columns为二维数组的列数（第二维长度）。 
 * 返 回 值：无
 */
void assignValuesTo2DArray(int **arr, int rows, int columns){
	// 请编程实现本函数
	    for(int i = 0; i < rows; i++) {
	        for(int j = 0; j < columns; j++) {
	            arr[i][j] = i * columns + j + 1;
	        }
	    }
}

/*
 * 函数名称：show2DArray
 * 函数功能：将形参arr所指向的二维数组的元素向屏幕输出显示，
 *           输出效果为rows行columns列 
 * 形式参数：arr为指向int型二维数组首地址的指针的指针；
 *           rows为二维数组的行数（第一维长度）；
 *           columns为二维数组的列数（第二维长度）。 
 * 返 回 值：无
 */
void show2DArray(int **arr, int rows, int columns){
	// 请编程实现本函数
	    for(int i = 0; i < rows; i++) {
	        for(int j = 0; j < columns; j++) {
	            printf("%4d", arr[i][j]);
	            if(j != columns - 1) {
	                printf(",");
	            }
	        }
	        printf("\n");
	    }
}

/*
 * 函数名称：create2DArray
 * 函数功能：创建rows行columns列的int型动态二维数组 
 * 形式参数：rows为二维数组的行数（第一维长度）；
 *           columns为二维数组的列数（第二维长度）。 
 * 返 回 值：无
 */
int **create2DArray(int rows, int columns){
	// 请编程实现本函数
	    int **arr = (int **)malloc(rows * sizeof(int *));
	    for(int i = 0; i < rows; i++) {
	        arr[i] = (int *)malloc(columns * sizeof(int));
	    }
	    return arr;
}

/*
 * 函数名称：free2DArray
 * 函数功能：释放二维数组内存空间
 * 形式参数：arr为指向int型二维数组首地址的指针的指针；
 *           rows为二维数组的行数（第一维长度）。
 * 返 回 值：无
 */
void free2DArray(int **array, int rows){
	// 请编程实现本函数
	for(int i = 0; i < rows; i++) {
	        free(array[i]);
	    }
	    free(array);
}

