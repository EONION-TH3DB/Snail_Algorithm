#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int i, j, k;
    int size;
    int cnt = 0;
    scanf_s("%d", &size);

    //2���� ���� �迭 ����
    int** arr = (int**)malloc(sizeof(int*) * size);
    for (i = 0; i < size; i++) {
        arr[i] = (int*)malloc(sizeof(int) * size);
    }
    
    // arr[size][size]�� �ð���� ���ư��� ������ �� �Է�
    for (i = 0; i < (size + 1) / 2; i++) {
        for (j = i; j < size-i-1; j++) {
            if (i == 0) {
                arr[i][j] = 1 + j;//ù��° ��Ŭ�� ������
                arr[j][size - i - 1] = arr[i][j] + (size - (i+1) * 2 + 1);//ù��° ��Ŭ�� �����ʼ���
                arr[size - i - 1][size - j - 1] = arr[i][j] + (size - (i+1) * 2 + 1) * 2;//ù��° ��Ŭ�� �ذ���
                arr[size - j - 1][i] = arr[i][j] + (size - (i+1) * 2 + 1) * 3;//ù��° ��Ŭ�� ���ʼ���
                cnt = arr[size - j - 1][i];//�ι�° ��Ŭ �����ϱ� ���� �ʱⰪ ����
            }
            else {
                arr[i][j] = 1 + cnt;//N��° ��Ŭ�� ������
                arr[j][size - i - 1] = arr[i][j] + (size - (i + 1) * 2 + 1);//N��° ��Ŭ�� �����ʼ���
                arr[size - i - 1][size - j - 1] = arr[i][j] + (size - (i + 1) * 2 + 1) * 2;//N��° ��Ŭ�� �ذ���
                arr[size - j - 1][i] = arr[i][j] + (size - (i + 1) * 2 + 1) * 3;//N��° ��Ŭ�� ���ʼ���
                if (j == size - i - 2) {
                    cnt = arr[size - j - 1][i];//N+1��° ��Ŭ �ʱⰪ
                }
                else {
                    cnt++;//J �ݺ������� N��° ��Ŭä��� ���� 1�� ������
                }                
            }
        }
        if (size % 2 == 1 && i==(size+1)/2-1 && j == size - i - 1) {
            arr[i][j] = 1 + cnt;//���� Ȧ �� �϶� ������ ��Ŭ ����ó��
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (arr[i][j]<10) {
                printf("  %d", arr[i][j]);
            }
            else {
                printf(" %d", arr[i][j]);
            }
        }
        printf("\n");
    }    

    for (i = 0; i < size; i++) {//���� �迭 �Ҵ�����
        free(arr[i]);
    }
    free(arr);

    return 0;
}