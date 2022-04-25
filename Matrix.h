/*
	�s��f�[�^��ێ�
*/
#ifndef MATRIX_H
#define MATRIX_H


//�s��̍\���̂̌^
typedef struct S_Matrix
{
	int		Row;	//�s��
	int		Column;	//��
	double	**Element;	//�v�f(����)��ێ�
} TS_Matrix;


//������
void Matrix_Initialize(TS_Matrix* Matrix,int StartRow,int StartColumn);

//�`��
//�s��
void Matrix_Draw_Row(TS_Matrix* Matrix);
//��
void Matrix_Draw_Column(TS_Matrix* Matrix);
//(i,j)����
void Matrix_Draw_Element(TS_Matrix* Matrix,int i,int j);
//�v�f�S��
void Matrix_Draw_Element_All(TS_Matrix* Matrix);

//�擾�p
//�s��
int Matrix_Get_Row(TS_Matrix* Matrix);
//��
int Matrix_Get_Column(TS_Matrix* Matrix);
//(i,j)����
double Matrix_Get_Element(TS_Matrix* Matrix,int i,int j);

//�ݒ�p
//�s��
int Matrix_Set_Row(TS_Matrix* Matrix,int NewRow);
//��
int Matrix_Set_Column(TS_Matrix* Matrix,int NewColumn);
//(i,j)����
double Matrix_Set_Element(TS_Matrix* Matrix,int i,int j,double NewElement);

//�X�V
int Matrix_Update(TS_Matrix* Matrix);
//�s�����X�V
int Matrix_Update_Row(TS_Matrix* Matrix,int NewRow);
//�񐔂��X�V
int Matrix_Update_Column(TS_Matrix* Matrix,int NewColumn);

//���Z
//���Z
TS_Matrix Matrix_Sum(TS_Matrix MA,TS_Matrix MB);
//���Z
TS_Matrix Matrix_Sub(TS_Matrix MA,TS_Matrix MB);
//��Z
TS_Matrix Matrix_Mul(TS_Matrix MA,TS_Matrix MB);
//���Z
TS_Matrix Matrix_Div(TS_Matrix MA,TS_Matrix MB);

//�I��
void Matrix_Finalize(TS_Matrix* Matrix);

#endif