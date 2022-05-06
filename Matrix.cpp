#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

//初期化
void Matrix_Initialize(TS_Matrix* Matrix,int StartRow,int StartColumn)
{
	//ループ用
	int i;

	//行数、列数を設定
	Matrix->Row = StartRow;
	Matrix->Column = StartColumn;

	//配列割り当て
	//行方向
	Matrix->Element = (double**)calloc(StartRow,sizeof(double*));
	//列方向
	for( i = 0 ; i < StartRow ; i++ )
	{
		Matrix->Element[i] = (double*)calloc(StartColumn,sizeof(double));
	}
}

//描画
//行数
void Matrix_Draw_Row(TS_Matrix* Matrix)
{
	printf("Number of row:%d\n",Matrix->Row);
}
//列数
void Matrix_Draw_Column(TS_Matrix* Matrix)
{
	printf("Number of column:%d\n",Matrix->Column);
}
//(i,j)成分
void Matrix_Draw_Element(TS_Matrix* Matrix,int i,int j)
{
	printf("(%d,%d)element:%f\n",i,j,Matrix->Element[i][j]);
}
//要素全部
void Matrix_Draw_Element_All(TS_Matrix* Matrix)
{
	int i,j;	//ループ用
	for( i = 0 ; i < Matrix->Row ; i++ )
	{	//行方向へ進めるループ
		for( j = 0 ; j < Matrix->Column ; j++ )
		{	//列方向へ進めるループ
			//表示
			printf("%8.4f ",Matrix->Element[i][j]);
		}
		//次の行に行く前に改行
		printf("\n");
	}
}

//取得用
//行数
int Matrix_Get_Row(TS_Matrix* Matrix)
{
	return (Matrix->Row);
}
//列数
int Matrix_Get_Column(TS_Matrix* Matrix)
{
	return (Matrix->Column);
}
//(i,j)成分
double Matrix_Get_Element(TS_Matrix* Matrix,int i,int j)
{
	return (Matrix->Element[i][j]);
}

//設定用
//行数
int Matrix_Set_Row(TS_Matrix* Matrix,int NewRow)
{
	Matrix->Row = NewRow;
	return (Matrix->Row);
}
//列数
int Matrix_Set_Column(TS_Matrix* Matrix,int NewColumn)
{
	Matrix->Column = NewColumn;
	return (Matrix->Column);
}
//(i,j)成分
double Matrix_Set_Element(TS_Matrix* Matrix,int i,int j,double NewElement)
{
	Matrix->Element[i][j] = NewElement;
	return (Matrix->Element[i][j]);
}

//更新
int Matrix_Update(TS_Matrix* Matrix)
{
	return (0);
}
//行数を更新
int Matrix_Update_Row(TS_Matrix* Matrix,int NewRow)
{
	//ループ用
	int i,j;

	//更新前の行列
	TS_Matrix *OldMatrix;
	OldMatrix = Matrix;

	//作業用
	double** tmp;

	//再割り当て
	if( (tmp = (double**)realloc(Matrix->Element,NewRow)) == NULL )
	{	//失敗したら
		//その旨を伝えて
		printf("\"Matrix_Update_Row\" is failed.\n");
		
		//もとに戻して
		Matrix = OldMatrix;
		
		//終了
		return (-1);
	}
	else
	{	//成功したら
		//代入
		Matrix->Element = tmp;

		//追加した部分をゼロクリア
		for( i = OldMatrix->Row ; i < NewRow ; i++ )
		{	//増えた部分を進むループ
			for( j = 0 ; j < OldMatrix->Column ; j++ )
			{	//列方向に進むループ
				Matrix->Element[i][j] = 0.0;
			}
		}

		//新しい行列のアドレス
		printf("%p\n",Matrix->Element);
	}

	//正常終了
	return (0);
}
//列数を更新
int Matrix_Update_Column(TS_Matrix* Matrix,int NewColumn)
{
	//ループ用
	int i,j;

	//更新前の行列
	TS_Matrix *OldMatrix;
	OldMatrix = Matrix;

	//作業用
	double* tmp;

	//再割り当て
	for( i = 0 ; i < OldMatrix->Row ; i++ )
	{	//行方向に進むループ
		if( ( tmp = (double*)realloc(Matrix->Element[i],NewColumn) ) == NULL )
		{	//失敗したら
			//その旨を伝えて
			printf("\"Matrix_Update_Row\" is failed.\n");
			
			//もとに戻して
			Matrix = OldMatrix;
			
			//終了
			return (-1);
		}
		else
		{	//成功したら
			//代入
			Matrix->Element[i] = tmp;

			//追加した部分をゼロクリア
			for( j = OldMatrix->Column ; j < NewColumn ; j++ )
			{	//列方向に進むループ
				Matrix->Element[i][j] = 0.0;
			}

			//新しい行列のアドレス
			printf("%p\n",Matrix->Element[i]);
		}
	}
	
	//正常終了
	return (0);
}

//演算
//加算
TS_Matrix Matrix_Sum(TS_Matrix MA,TS_Matrix MB)
{
	//計算結果を格納
	TS_Matrix Result = { 0 , 0 , NULL };

	//型が一致していなければ計算不可なのでヌルを返す
	if( MA.Row != MB.Row || MA.Column != MB.Column )
	{
		return (Result);
	}
	else
	{	//一致していれば
		//結果格納用構造体を初期化
		Matrix_Initialize( &Result , MA.Row , MA.Column );
	}

	//ループ用
	int i,j;

	//演算
	for( i = 0 ; i < Result.Row ; i++ )
	{	//行方向のループ
		for( j = 0 ; j < Result.Column ; j++ )
		{	//列方向のループ
			//加算したものを結果用変数のメンバへ
			Result.Element[i][j] = MA.Element[i][j] + MB.Element[i][j];
		}
	}

	//返却
	return (Result);
}
//減算
TS_Matrix Matrix_Sub(TS_Matrix MA,TS_Matrix MB)
{
	//計算結果を格納
	TS_Matrix Result = { 0 , 0 , NULL };

	//型が一致していなければ計算不可なのでヌルを返す
	if( MA.Row != MB.Row || MA.Column != MB.Column )
	{
		return (Result);
	}
	else
	{	//一致していれば
		//結果格納用構造体を初期化
		Matrix_Initialize( &Result , MA.Row , MA.Column );
	}

	//ループ用
	int i,j;

	//演算
	for( i = 0 ; i < Result.Row ; i++ )
	{	//行方向のループ
		for( j = 0 ; j < Result.Column ; j++ )
		{	//列方向のループ
			//加算したものを結果用変数のメンバへ
			Result.Element[i][j] = MA.Element[i][j] - MB.Element[i][j];
		}
	}

	//返却
	return (Result);
}
//乗算
TS_Matrix Matrix_Mul(TS_Matrix MA,TS_Matrix MB)
{
	//計算結果を格納
	TS_Matrix Result = { 0 , 0 , NULL };

	//左側の列数と右側の行数が一致していなければ計算不可なのでヌルを返す
	if( MA.Column != MB.Row )
	{
		return (Result);
	}
	else
	{	//一致していれば
		//結果格納用構造体を初期化
		Matrix_Initialize( &Result , MA.Row , MB.Column );
	}

	//ループ用
	int i,j,k;

	//演算
	for( i = 0 ; i < Result.Row ; i++ )
	{	//行方向のループ
		for( j = 0 ; j < Result.Column ; j++ )
		{	//列方向のループ
			//行列乗算したものを結果用変数のメンバへ
			for( k = 0 ; k < MB.Row ; k++ )
			{
				Result.Element[i][j] += MA.Element[i][k] * MB.Element[k][j];
			}
		}
	}

	//返却
	return (Result);
}
//除算
TS_Matrix Matrix_Div(TS_Matrix MA,TS_Matrix MB)
{
	//計算結果を格納
	TS_Matrix Result = { 0 , 0 , NULL };

	//左側の列数と右側の行数が一致していなければ計算不可なのでヌルを返す
	if( MA.Column != MB.Row )
	{
		return (Result);
	}
	else
	{	//一致していれば
		//結果格納用構造体を初期化
		Matrix_Initialize( &Result , MA.Row , MB.Column );
	}

	//ループ用
	int i,j,k;

	//演算
	for( i = 0 ; i < Result.Row ; i++ )
	{	//行方向のループ
		for( j = 0 ; j < Result.Column ; j++ )
		{	//列方向のループ
			//行列乗算したものを結果用変数のメンバへ
			for( k = 0 ; k < MB.Row ; k++ )
			{
				Result.Element[i][j] += MA.Element[i][k] / MB.Element[k][j];
			}
		}
	}

	//返却
	return (Result);
}
//LU分解を行う
void Matrix_LUDecomposition(TS_Matrix MA,TS_Matrix* ML,TS_Matrix* MU)
{
	//ループ用
	int i,j,k;

	//結果一時収納場所
	double tmp = 0.0;

	//分解の演算を行う
	for( i = 0 ; i < MA.Row ; i++ )
	{	//分解される行列の行数分ループする

		//Lの(i,i)成分を更新
		ML->Element[i][i] = 1.0;

		//Uの(i,i)成分を更新
		tmp = 0.0;
		//漸化式の部分を計算
		for( k = 0 ; k < i ; k++ )
		{
			tmp += ML->Element[i][k] * MU->Element[k][i];
		}
		//代入
		MU->Element[i][i] = MA.Element[i][i] - tmp;

		for( j = i+1 ; j < MA.Column ; j++ )
		{	//分解される行列の列数分ループする
			//Lの(j,i)成分を更新
			//漸化式の部分を計算
			tmp = 0.0;
			for( k = 0 ; k < i ; k++ )
			{
				tmp += ML->Element[j][k] * MU->Element[k][i];
			}
			//代入
			ML->Element[j][i] = (MA.Element[j][i] - tmp) / MU->Element[i][i];

			//Uの(j,i)成分を更新
			MU->Element[j][i] = 0.0;

			//Lの(i,j)成分を更新
			ML->Element[i][j] = 0.0;

			//Uの(i,j)成分を更新
			//漸化式の部分を計算
			tmp = 0.0;
			for( k = 0 ; k < i ; k++ )
			{
				tmp += ML->Element[i][k] * MU->Element[k][j];
			}
			//代入
			MU->Element[i][j] = MA.Element[i][j] - tmp;
		}
	}
}



//終了
void Matrix_Finalize(TS_Matrix* Matrix)
{
	int i;	//ループ用
	//要素の列の部分を解放
	for( i = 0 ; i < Matrix->Row ; i++ )
	{
		free(Matrix->Element[i]);
	}
	//要素の全体を開放
	free(Matrix->Element);
}
