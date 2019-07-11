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
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, j, m, l, pivot;

// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[n-1];
  A[n-1] = pivot;
    l = n - 2;
  for(i = j = m = 0; i < (n-1); i++){
    if(A[m] < pivot){
      swap(A+m, A+j);
      j++;
      m++;
    }
    else if(A[m] == pivot){
        swap(A+m,A+l);
            l--;
        }
    else m++;
  }

  if(j+n-l-1 >= k+1 && k+1 > j ) return pivot;
  else if(j >= k+1) return quick_select(A+0, j, k);
  else return quick_select(A+j, n-j-(n-l-1), k-j-(n-l-1));
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
 A[i] = (long long int) A[i-1] * A[0] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
  //  if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
