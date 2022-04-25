#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

//������
void Matrix_Initialize(TS_Matrix* Matrix,int StartRow,int StartColumn)
{
	//���[�v�p
	int i;

	//�s���A�񐔂�ݒ�
	Matrix->Row = StartRow;
	Matrix->Column = StartColumn;

	//�z�񊄂蓖��
	//�s����
	Matrix->Element = (double**)calloc(StartRow,sizeof(double*));
	//�����
	for( i = 0 ; i < StartRow ; i++ )
	{
		Matrix->Element[i] = (double*)calloc(StartColumn,sizeof(double));
	}
}

//�`��
//�s��
void Matrix_Draw_Row(TS_Matrix* Matrix)
{
	printf("Number of row:%d\n",Matrix->Row);
}
//��
void Matrix_Draw_Column(TS_Matrix* Matrix)
{
	printf("Number of column:%d\n",Matrix->Column);
}
//(i,j)����
void Matrix_Draw_Element(TS_Matrix* Matrix,int i,int j)
{
	printf("(%d,%d)element:%f\n",i,j,Matrix->Element[i][j]);
}
//�v�f�S��
void Matrix_Draw_Element_All(TS_Matrix* Matrix)
{
	int i,j;	//���[�v�p
	for( i = 0 ; i < Matrix->Row ; i++ )
	{	//�s�����֐i�߂郋�[�v
		for( j = 0 ; j < Matrix->Column ; j++ )
		{	//������֐i�߂郋�[�v
			//�\��
			printf("%8.4f ",Matrix->Element[i][j]);
		}
		//���̍s�ɍs���O�ɉ��s
		printf("\n");
	}
}

//�擾�p
//�s��
int Matrix_Get_Row(TS_Matrix* Matrix)
{
	return (Matrix->Row);
}
//��
int Matrix_Get_Column(TS_Matrix* Matrix)
{
	return (Matrix->Column);
}
//(i,j)����
double Matrix_Get_Element(TS_Matrix* Matrix,int i,int j)
{
	return (Matrix->Element[i][j]);
}

//�ݒ�p
//�s��
int Matrix_Set_Row(TS_Matrix* Matrix,int NewRow)
{
	Matrix->Row = NewRow;
	return (Matrix->Row);
}
//��
int Matrix_Set_Column(TS_Matrix* Matrix,int NewColumn)
{
	Matrix->Column = NewColumn;
	return (Matrix->Column);
}
//(i,j)����
double Matrix_Set_Element(TS_Matrix* Matrix,int i,int j,double NewElement)
{
	Matrix->Element[i][j] = NewElement;
	return (Matrix->Element[i][j]);
}

//�X�V
int Matrix_Update(TS_Matrix* Matrix)
{
	return (0);
}
//�s�����X�V
int Matrix_Update_Row(TS_Matrix* Matrix,int NewRow)
{
	//���[�v�p
	int i,j;

	//�X�V�O�̍s��
	TS_Matrix *OldMatrix;
	OldMatrix = Matrix;

	//��Ɨp
	double** tmp;

	//�Ċ��蓖��
	if( (tmp = (double**)realloc(Matrix->Element,NewRow)) == NULL )
	{	//���s������
		//���̎|��`����
		printf("\"Matrix_Update_Row\" is failed.\n");
		
		//���Ƃɖ߂���
		Matrix = OldMatrix;
		
		//�I��
		return (-1);
	}
	else
	{	//����������
		//���
		Matrix->Element = tmp;

		//�ǉ������������[���N���A
		for( i = OldMatrix->Row ; i < NewRow ; i++ )
		{	//������������i�ރ��[�v
			for( j = 0 ; j < OldMatrix->Column ; j++ )
			{	//������ɐi�ރ��[�v
				Matrix->Element[i][j] = 0.0;
			}
		}

		//�V�����s��̃A�h���X
		printf("%p\n",Matrix->Element);
	}

	//����I��
	return (0);
}
//�񐔂��X�V
int Matrix_Update_Column(TS_Matrix* Matrix,int NewColumn)
{
	//���[�v�p
	int i,j;

	//�X�V�O�̍s��
	TS_Matrix *OldMatrix;
	OldMatrix = Matrix;

	//��Ɨp
	double* tmp;

	//�Ċ��蓖��
	for( i = 0 ; i < OldMatrix->Row ; i++ )
	{	//�s�����ɐi�ރ��[�v
		if( ( tmp = (double*)realloc(Matrix->Element[i],NewColumn) ) == NULL )
		{	//���s������
			//���̎|��`����
			printf("\"Matrix_Update_Row\" is failed.\n");
			
			//���Ƃɖ߂���
			Matrix = OldMatrix;
			
			//�I��
			return (-1);
		}
		else
		{	//����������
			//���
			Matrix->Element[i] = tmp;

			//�ǉ������������[���N���A
			for( j = OldMatrix->Column ; j < NewColumn ; j++ )
			{	//������ɐi�ރ��[�v
				Matrix->Element[i][j] = 0.0;
			}

			//�V�����s��̃A�h���X
			printf("%p\n",Matrix->Element[i]);
		}
	}
	
	//����I��
	return (0);
}

//���Z
//���Z
TS_Matrix Matrix_Sum(TS_Matrix MA,TS_Matrix MB)
{
	//�v�Z���ʂ��i�[
	TS_Matrix Result = { 0 , 0 , NULL };

	//�^����v���Ă��Ȃ���Όv�Z�s�Ȃ̂Ńk����Ԃ�
	if( MA.Row != MB.Row || MA.Column != MB.Column )
	{
		return (Result);
	}
	else
	{	//��v���Ă����
		//���ʊi�[�p�\���̂�������
		Matrix_Initialize( &Result , MA.Row , MA.Column );
	}

	//���[�v�p
	int i,j;

	//���Z
	for( i = 0 ; i < Result.Row ; i++ )
	{	//�s�����̃��[�v
		for( j = 0 ; j < Result.Column ; j++ )
		{	//������̃��[�v
			//���Z�������̂����ʗp�ϐ��̃����o��
			Result.Element[i][j] = MA.Element[i][j] + MB.Element[i][j];
		}
	}

	//�ԋp
	return (Result);
}
//���Z
TS_Matrix Matrix_Sub(TS_Matrix MA,TS_Matrix MB)
{
	//�v�Z���ʂ��i�[
	TS_Matrix Result = { 0 , 0 , NULL };

	//�^����v���Ă��Ȃ���Όv�Z�s�Ȃ̂Ńk����Ԃ�
	if( MA.Row != MB.Row || MA.Column != MB.Column )
	{
		return (Result);
	}
	else
	{	//��v���Ă����
		//���ʊi�[�p�\���̂�������
		Matrix_Initialize( &Result , MA.Row , MA.Column );
	}

	//���[�v�p
	int i,j;

	//���Z
	for( i = 0 ; i < Result.Row ; i++ )
	{	//�s�����̃��[�v
		for( j = 0 ; j < Result.Column ; j++ )
		{	//������̃��[�v
			//���Z�������̂����ʗp�ϐ��̃����o��
			Result.Element[i][j] = MA.Element[i][j] - MB.Element[i][j];
		}
	}

	//�ԋp
	return (Result);
}
//��Z
TS_Matrix Matrix_Mul(TS_Matrix MA,TS_Matrix MB)
{
	//�v�Z���ʂ��i�[
	TS_Matrix Result = { 0 , 0 , NULL };

	//�����̗񐔂ƉE���̍s������v���Ă��Ȃ���Όv�Z�s�Ȃ̂Ńk����Ԃ�
	if( MA.Column != MB.Row )
	{
		return (Result);
	}
	else
	{	//��v���Ă����
		//���ʊi�[�p�\���̂�������
		Matrix_Initialize( &Result , MA.Row , MB.Column );
	}

	//���[�v�p
	int i,j,k;

	//���Z
	for( i = 0 ; i < Result.Row ; i++ )
	{	//�s�����̃��[�v
		for( j = 0 ; j < Result.Column ; j++ )
		{	//������̃��[�v
			//�s���Z�������̂����ʗp�ϐ��̃����o��
			for( k = 0 ; k < MB.Row ; k++ )
			{
				Result.Element[i][j] += MA.Element[i][k] * MB.Element[k][j];
			}
		}
	}

	//�ԋp
	return (Result);
}
//���Z
TS_Matrix Matrix_Div(TS_Matrix MA,TS_Matrix MB)
{
	//�v�Z���ʂ��i�[
	TS_Matrix Result = { 0 , 0 , NULL };

	//�����̗񐔂ƉE���̍s������v���Ă��Ȃ���Όv�Z�s�Ȃ̂Ńk����Ԃ�
	if( MA.Column != MB.Row )
	{
		return (Result);
	}
	else
	{	//��v���Ă����
		//���ʊi�[�p�\���̂�������
		Matrix_Initialize( &Result , MA.Row , MB.Column );
	}

	//���[�v�p
	int i,j,k;

	//���Z
	for( i = 0 ; i < Result.Row ; i++ )
	{	//�s�����̃��[�v
		for( j = 0 ; j < Result.Column ; j++ )
		{	//������̃��[�v
			//�s���Z�������̂����ʗp�ϐ��̃����o��
			for( k = 0 ; k < MB.Row ; k++ )
			{
				Result.Element[i][j] += MA.Element[i][k] / MB.Element[k][j];
			}
		}
	}

	//�ԋp
	return (Result);
}

//�I��
void Matrix_Finalize(TS_Matrix* Matrix)
{
	int i;	//���[�v�p
	//�v�f�̗�̕��������
	for( i = 0 ; i < Matrix->Row ; i++ )
	{
		free(Matrix->Element[i]);
	}
	//�v�f�̑S�̂��J��
	free(Matrix->Element);
}