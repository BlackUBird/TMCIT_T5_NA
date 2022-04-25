#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main()
{
	int rows,cols;	//�s��,��
	//�擾
	printf("�s�������:");	scanf_s("%d",&rows);
	printf("�񐔂����:");	scanf_s("%d",&cols);

	//�s����쐬
	TS_Matrix M_A;
	Matrix_Initialize( &M_A , rows , cols );
	TS_Matrix M_B;
	Matrix_Initialize( &M_B , rows , cols );

	//�\��
	puts("Matrix:A");
	Matrix_Draw_Row( &M_A );	//�s��
	Matrix_Draw_Column( &M_A );	//��
	Matrix_Draw_Element_All( &M_A );	//�S�Ă̗v�f
	puts("Matrix:B");
	Matrix_Draw_Row( &M_B );	//�s��
	Matrix_Draw_Column( &M_B );	//��
	Matrix_Draw_Element_All( &M_B );	//�S�Ă̗v�f

	//�e�X�g�p�s��
	double test_m[3][3] = 
	{
		{ 1 , 2 , 3 },
		{ 4 , 5 , 6 },
		{ 7 , 8 , 9 },
	};

	//�ݒ�
	//���[�v�p
	int i,j;
	for( i = 0 ; i < 3 ; i++ )
	{	//�s�����֐i�ރ��[�v
		for( j = 0 ; j < 3 ; j++ )
		{	//������֐i�ރ��[�v
			Matrix_Set_Element( &M_A , i , j , test_m[i][j] );
			Matrix_Set_Element( &M_B , i , j , test_m[j][i] );
		}
	}
	//�ēx�\��
	puts("Matrix:A");
	Matrix_Draw_Row( &M_A );	//�s��
	Matrix_Draw_Column( &M_A );	//��
	Matrix_Draw_Element_All( &M_A );	//�S�Ă̗v�f
	puts("Matrix:B");
	Matrix_Draw_Row( &M_B );	//�s��
	Matrix_Draw_Column( &M_B );	//��
	Matrix_Draw_Element_All( &M_B );	//�S�Ă̗v�f

	//���ʊi�[�p
	TS_Matrix M_Result;
	Matrix_Initialize( &M_Result , rows , cols );

	//���Z
	M_Result = Matrix_Sum( M_A , M_B );
	//�\��
	puts("Matrix:Result(SUM)");
	Matrix_Draw_Row( &M_Result );	//�s��
	Matrix_Draw_Column( &M_Result );	//��
	Matrix_Draw_Element_All( &M_Result );	//�S�Ă̗v�f

	//���Z
	M_Result = Matrix_Sub( M_A , M_B );
	//�\��
	puts("Matrix:Result(SUB)");
	Matrix_Draw_Row( &M_Result );	//�s��
	Matrix_Draw_Column( &M_Result );	//��
	Matrix_Draw_Element_All( &M_Result );	//�S�Ă̗v�f

	//��Z
	M_Result = Matrix_Mul( M_A , M_B );
	//�\��
	puts("Matrix:Result(MUL)");
	Matrix_Draw_Row( &M_Result );	//�s��
	Matrix_Draw_Column( &M_Result );	//��
	Matrix_Draw_Element_All( &M_Result );	//�S�Ă̗v�f

	//���Z
	M_Result = Matrix_Div( M_A , M_B );
	//�\��
	puts("Matrix:Result(DIV)");
	Matrix_Draw_Row( &M_Result );	//�s��
	Matrix_Draw_Column( &M_Result );	//��
	Matrix_Draw_Element_All( &M_Result );	//�S�Ă̗v�f

	system("pause");

	//�I��
	Matrix_Finalize( &M_A );
	Matrix_Finalize( &M_B );

	return (0);
}