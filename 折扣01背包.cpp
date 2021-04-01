#include <stdio.h>
#include<stdlib.h>

int  idkp0[2][3*10],idkp1[2][3*100];

// �����ݣ������������ݱ��浽������ 
int getData()
{
	FILE *fpRead = fopen("idkp1-10.txt","r");
	
	if(fpRead == NULL) 
	{
		return 0;
	}
	
	for(int i=0;i<3*10;i++) 
		fscanf(fpRead,"%d,",&idkp0[0][i]);
	for(int i=0;i<3*10;i++) 
		fscanf(fpRead,"%d,",&idkp0[1][i]);

	for(int i=0;i<3*100;i++) 
		fscanf(fpRead,"%d,",&idkp1[0][i]);
	for(int i=0;i<3*100;i++) 
		fscanf(fpRead,"%d,",&idkp1[1][i]);
}

// ���������ļ�ֵ/�����Ƚ��зǵ������� 
void Bubble_sort(int len)
{
    int tmp1 = 0,tmp2 = 0,tmp3 = 0,tmp4 = 0,tmp5 = 0,tmp6 = 0;
    bool swap = false;//���ж�����  ���ٱȽϴ���
    for(int i=0;i<len-1;i++) 
	{
        for(int j=0;j<len-1-i;j++)
        {
            if((j+1)%3 == 0 && ((idkp0[0][j]/idkp0[1][j]) < (idkp0[0][j+3]/idkp0[1][j+3])))
            {
                tmp1 = idkp0[0][j];
                idkp0[0][j] = idkp0[0][j+3];
                idkp0[0][j+3] = tmp1;//����
                
                tmp2 = idkp0[0][j-1];
                idkp0[0][j-1] = idkp0[0][j+2];
                idkp0[0][j+2] = tmp2;//����
                
                tmp3 = idkp0[0][j-2];
                idkp0[0][j-2] = idkp0[0][j+1];
                idkp0[0][j+1] = tmp3;//����
                
                tmp4 = idkp0[1][j];
                idkp0[1][j] = idkp0[1][j+3];
                idkp0[1][j+3] = tmp4;//����
                
                tmp5 = idkp0[1][j-1];
                idkp0[1][j-1] = idkp0[1][j+2];
                idkp0[1][j+2] = tmp5;//����
                
                tmp6 = idkp0[1][j-2];
                idkp0[1][j-2] = idkp0[1][j+1];
                idkp0[1][j+1] = tmp6;//����
                
                swap = true;
            }
        }
        if (!swap)
		{
            return;
        }
    }
}


int V[100][100];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ

int max(int a,int b){
   if(a>=b)
       return a;
   else return b;
}

void Baggage(int level,int n,int temp_weight,int temp_value,int weight[],int value[])
{
	if(level>=n+1)
	{
		if(temp_value>max_value)
		{
			max_value = temp_value;
		}
	}
	else
	{
		if(temp_weight>=weight[level+1])
		{
			temp_weight = temp_weight - weight[level+1];
			temp_value = temp_value + value[level+1];
			Baggage(level+1,n,temp_weight,temp_value,weight,value);
			temp_weight = temp_weight + weight[level+1];
			temp_value = temp_value - value[level+1];
		}
		Baggage(level+1,n,temp_weight,temp_value,weight,value);
	}
}


int main() 
{
	getData();
	
	printf("��ֵ:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[0][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[0][i]);
		else
			printf("%d,",idkp0[0][i]);
	}
	printf("\n����:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[1][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[1][i]);
		else
			printf("%d,",idkp0[1][i]);
	}
	printf("\n");
	
	Bubble_sort(3*10);
	
	printf("\n�����\n\n");
	printf("��ֵ:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[0][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[0][i]);
		else
			printf("%d,",idkp0[0][i]);
	}
	printf("\n����:\n");
	for(int i=0;i<3*10;i++)
	{
		if((i+1)%3 == 0)
			printf("%d] ",idkp0[1][i]);
		else if((i+3)%3 == 0)
			printf("[%d,",idkp0[1][i]);
		else
			printf("%d,",idkp0[1][i]);
	}
	printf("\n");
	
} 
