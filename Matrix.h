/*
	行列データを保持
*/
#ifndef MATRIX_H
#define MATRIX_H


//行列の構造体の型
typedef struct S_Matrix
{
	int		Row;	//行数
	int		Column;	//列数
	double	**Element;	//要素(成分)を保持
} TS_Matrix;

//初期化
void Matrix_Initialize(TS_Matrix* Matrix,int StartRow,int StartColumn);

//描画
//行数
void Matrix_Draw_Row(TS_Matrix* Matrix);
//列数
void Matrix_Draw_Column(TS_Matrix* Matrix);
//(i,j)成分
void Matrix_Draw_Element(TS_Matrix* Matrix,int i,int j);
//要素全部
void Matrix_Draw_Element_All(TS_Matrix* Matrix);

//取得用
//行数
int Matrix_Get_Row(TS_Matrix* Matrix);
//列数
int Matrix_Get_Column(TS_Matrix* Matrix);
//(i,j)成分
double Matrix_Get_Element(TS_Matrix* Matrix,int i,int j);

//設定用
//行数
int Matrix_Set_Row(TS_Matrix* Matrix,int NewRow);
//列数
int Matrix_Set_Column(TS_Matrix* Matrix,int NewColumn);
//(i,j)成分
double Matrix_Set_Element(TS_Matrix* Matrix,int i,int j,double NewElement);

//更新
int Matrix_Update(TS_Matrix* Matrix);
//行数を更新
int Matrix_Update_Row(TS_Matrix* Matrix,int NewRow);
//列数を更新
int Matrix_Update_Column(TS_Matrix* Matrix,int NewColumn);

//演算とか
//加算
TS_Matrix Matrix_Sum(TS_Matrix MA,TS_Matrix MB);
//減算
TS_Matrix Matrix_Sub(TS_Matrix MA,TS_Matrix MB);
//乗算
TS_Matrix Matrix_Mul(TS_Matrix MA,TS_Matrix MB);
//除算
TS_Matrix Matrix_Div(TS_Matrix MA,TS_Matrix MB);
//LU分解を行う
void Matrix_LUDecomposition(TS_Matrix MA,TS_Matrix* ML,TS_Matrix* MU);

//終了
void Matrix_Finalize(TS_Matrix* Matrix);

#endif
