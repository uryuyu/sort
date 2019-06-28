#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    if(n == 0|| n == 1) return ;
    else {
        int i,j,k,l,pivot;
        pivot = A[n/2];
        A[n/2] = A[n-1];
        A[n-1] = pivot;
        l = n - 2;
        for(i = j = k = 0; i < (n-1); i++){
            if(A[k] < pivot){
                swap(A+k,A+j);
                j++;
                k++;
            }
            else if(A[k] == pivot){
                swap(A+k,A+l);
                l--;
            }
            else k++;
        }
        int m = n-1;
        for(i = j; i < (n - l - 1 + j); i ++){
            swap(A+i,A+m);
            m--;
        }
        return quick_sort(A, j),quick_sort(A+(j+n-l-1), n-j-(n-1-l));
    }
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
