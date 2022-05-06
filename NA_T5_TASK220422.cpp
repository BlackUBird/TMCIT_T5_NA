#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(void)
{
	int rows,cols;	//行数,列数
	//取得
	printf("行数を入力:");	scanf_s("%d",&rows);
	printf("列数を入力:");	scanf_s("%d",&cols);

	//行列を作成
	TS_Matrix M_A;
	Matrix_Initialize( &M_A , rows , cols );
	TS_Matrix M_B;
	Matrix_Initialize( &M_B , rows , cols );

	//表示
	puts("Matrix:A");
	Matrix_Draw_Row( &M_A );	//行数
	Matrix_Draw_Column( &M_A );	//列数
	Matrix_Draw_Element_All( &M_A );	//全ての要素
	puts("");
	puts("Matrix:B");
	Matrix_Draw_Row( &M_B );	//行数
	Matrix_Draw_Column( &M_B );	//列数
	Matrix_Draw_Element_All( &M_B );	//全ての要素
	puts("");

	//設定
	//ループ用
	int i,j;
	//入力を促す
	printf("行列Aの要素を入力してください\n");
	//入力を受ける
	double element;
	for( i = 0 ; i < 3 ; i++ )
	{	//行方向へ進むループ
		for( j = 0 ; j < 3 ; j++ )
		{	//列方向へ進むループ
			//入力
			printf("(%d,%d):",i,j);	scanf_s("%lf",&element);
			//設定
			Matrix_Set_Element( &M_A , i , j , element );
			Matrix_Set_Element( &M_B , i , j , 20.0 - element );
		}
	}
	//再度表示
	puts("Matrix:A");
	Matrix_Draw_Row( &M_A );	//行数
	Matrix_Draw_Column( &M_A );	//列数
	Matrix_Draw_Element_All( &M_A );	//全ての要素
	puts("");
	puts("Matrix:B");
	Matrix_Draw_Row( &M_B );	//行数
	Matrix_Draw_Column( &M_B );	//列数
	Matrix_Draw_Element_All( &M_B );	//全ての要素
	puts("");

	//結果格納用
	TS_Matrix M_Result;
	Matrix_Initialize( &M_Result , rows , cols );

	//加算
	M_Result = Matrix_Sum( M_A , M_B );
	//表示
	puts("Matrix:Result(SUM)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素
	puts("");

	//減算
	M_Result = Matrix_Sub( M_A , M_B );
	//表示
	puts("Matrix:Result(SUB)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素
	puts("");

	//乗算
	M_Result = Matrix_Mul( M_A , M_B );
	//表示
	puts("Matrix:Result(MUL)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素
	puts("");

	//除算
	M_Result = Matrix_Div( M_A , M_B );
	//表示
	puts("Matrix:Result(DIV)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素
	puts("");

	//LU分解
	//下三角行列
	TS_Matrix M_L;
	Matrix_Initialize( &M_L , rows ,cols );
	//上三角行列
	TS_Matrix M_U;
	Matrix_Initialize( &M_U , rows ,cols );
	//LU分解を行い、各三角行列を取得
	Matrix_LUDecomposition( M_A , &M_L ,&M_U );
	puts("LUDecomposition(A=LU)");
	//表示
	puts("Matrix:Result(A)");
	Matrix_Draw_Row( &M_A );	//行数
	Matrix_Draw_Column( &M_A );	//列数
	Matrix_Draw_Element_All( &M_A );	//全ての要素
	puts("");
	//表示
	puts("Matrix:Result(L)");
	Matrix_Draw_Row( &M_L );	//行数
	Matrix_Draw_Column( &M_L );	//列数
	Matrix_Draw_Element_All( &M_L );	//全ての要素
	puts("");
	//表示
	puts("Matrix:Result(U)");
	Matrix_Draw_Row( &M_U );	//行数
	Matrix_Draw_Column( &M_U );	//列数
	Matrix_Draw_Element_All( &M_U );	//全ての要素
	puts("");

	//LU分解したもので乗算
	M_Result = Matrix_Mul( M_L , M_U );
	//表示
	puts("Matrix:Result(L*U)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素
	puts("");

	system("pause");

	//終了
	Matrix_Finalize( &M_A );
	Matrix_Finalize( &M_B );
	Matrix_Finalize( &M_Result );
	Matrix_Finalize( &M_L );
	Matrix_Finalize( &M_U );

	return (0);
}
