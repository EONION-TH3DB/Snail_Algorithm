#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int i, j, k;
    int size;
    int cnt = 0;
    scanf_s("%d", &size);

    //2차원 동적 배열 생성
    int** arr = (int**)malloc(sizeof(int*) * size);
    for (i = 0; i < size; i++) {
        arr[i] = (int*)malloc(sizeof(int) * size);
    }
    
    // arr[size][size]에 시계방향 돌아가는 순서로 값 입력
    for (i = 0; i < (size + 1) / 2; i++) {
        for (j = i; j < size-i-1; j++) {
            if (i == 0) {
                arr[i][j] = 1 + j;//첫번째 써클의 윗가로
                arr[j][size - i - 1] = arr[i][j] + (size - (i+1) * 2 + 1);//첫번째 써클의 오른쪽세로
                arr[size - i - 1][size - j - 1] = arr[i][j] + (size - (i+1) * 2 + 1) * 2;//첫번째 써클의 밑가로
                arr[size - j - 1][i] = arr[i][j] + (size - (i+1) * 2 + 1) * 3;//첫번째 써클의 왼쪽세로
                cnt = arr[size - j - 1][i];//두번째 써클 실행하기 위한 초기값 설정
            }
            else {
                arr[i][j] = 1 + cnt;//N번째 서클의 윗가로
                arr[j][size - i - 1] = arr[i][j] + (size - (i + 1) * 2 + 1);//N번째 서클의 오른쪽세로
                arr[size - i - 1][size - j - 1] = arr[i][j] + (size - (i + 1) * 2 + 1) * 2;//N번째 서클의 밑가로
                arr[size - j - 1][i] = arr[i][j] + (size - (i + 1) * 2 + 1) * 3;//N번째 서클의 왼쪽세로
                if (j == size - i - 2) {
                    cnt = arr[size - j - 1][i];//N+1번째 써클 초기값
                }
                else {
                    cnt++;//J 반복문에서 N번째 써클채우기 위한 1씩 증가식
                }                
            }
        }
        if (size % 2 == 1 && i==(size+1)/2-1 && j == size - i - 1) {
            arr[i][j] = 1 + cnt;//값이 홀 수 일때 마지막 써클 예외처리
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

    for (i = 0; i < size; i++) {//동적 배열 할당해제
        free(arr[i]);
    }
    free(arr);

    return 0;
}