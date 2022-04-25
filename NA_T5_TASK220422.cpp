#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main()
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
	puts("Matrix:B");
	Matrix_Draw_Row( &M_B );	//行数
	Matrix_Draw_Column( &M_B );	//列数
	Matrix_Draw_Element_All( &M_B );	//全ての要素

	//テスト用行列
	double test_m[3][3] = 
	{
		{ 1 , 2 , 3 },
		{ 4 , 5 , 6 },
		{ 7 , 8 , 9 },
	};

	//設定
	//ループ用
	int i,j;
	for( i = 0 ; i < 3 ; i++ )
	{	//行方向へ進むループ
		for( j = 0 ; j < 3 ; j++ )
		{	//列方向へ進むループ
			Matrix_Set_Element( &M_A , i , j , test_m[i][j] );
			Matrix_Set_Element( &M_B , i , j , test_m[j][i] );
		}
	}
	//再度表示
	puts("Matrix:A");
	Matrix_Draw_Row( &M_A );	//行数
	Matrix_Draw_Column( &M_A );	//列数
	Matrix_Draw_Element_All( &M_A );	//全ての要素
	puts("Matrix:B");
	Matrix_Draw_Row( &M_B );	//行数
	Matrix_Draw_Column( &M_B );	//列数
	Matrix_Draw_Element_All( &M_B );	//全ての要素

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

	//減算
	M_Result = Matrix_Sub( M_A , M_B );
	//表示
	puts("Matrix:Result(SUB)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素

	//乗算
	M_Result = Matrix_Mul( M_A , M_B );
	//表示
	puts("Matrix:Result(MUL)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素

	//除算
	M_Result = Matrix_Div( M_A , M_B );
	//表示
	puts("Matrix:Result(DIV)");
	Matrix_Draw_Row( &M_Result );	//行数
	Matrix_Draw_Column( &M_Result );	//列数
	Matrix_Draw_Element_All( &M_Result );	//全ての要素

	system("pause");

	//終了
	Matrix_Finalize( &M_A );
	Matrix_Finalize( &M_B );

	return (0);
}