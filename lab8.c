#include <stdio.h>
#include <stdlib.h> // Для rand()
#include <time.h> // для time()

int rand_int(int min, int max) {
        return (rand() % (max - min + 1)) + min;
}


    


int main() {

int N,M;
srand(time(NULL));
scanf("%d",&N);
    int arr_2d[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr_2d[i][j] = rand_int(-100, 100);
        }
    }
switch(N){
        case 1: return arr_2d[0][0];
        case 2:
            return (arr_2d[0][0]*arr_2d[1][1])-(arr_2d[1][0]*arr_2d[0][1]);
        case 3: return 
            arr_2d[0][0]*arr_2d[1][1]*arr_2d[2][2]+//main diagonal
            arr_2d[1][0]*arr_2d[0][2]*arr_2d[2][1]+
            arr_2d[0][1]*arr_2d[2][0]*arr_2d[1][2]-
            arr_2d[0][2]*arr_2d[1][1]*arr_2d[2][0]+//second diagonal
            arr_2d[0][0]*arr_2d[2][1]*arr_2d[1][2]+
            arr_2d[0][1]*arr_2d[1][0]*arr_2d[2][2];
        default:
            printf("d,slad,las\n");
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr_2d[i][j]);
        }
        printf("\n");
    }
    
    

}
