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

int quick_select(int A[], int n, int k){
  int i, j, pivot;
    if(n<=5){
// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
  
}
    else {
        int l,m;
        l = (n+4)/5;
        int B[l];
        for(m = 0;m < l;m ++){
            if(l - m > 1){
                B[m] = quick_select(A+(m*5),5, 2);
            }
            else {
                B[m] = quick_select(A+(m*5),n-(m*5),(n-(m*5))/2);
            }
        }
        pivot = quick_select(B, l, l/2);
        
        int r,s,t;
        int C[N],D[N];
        r = s = t = 0;
        while (r + s + t < n) {
            if(A[r+s+t] < pivot){
                C[r] = A[r+s+t];
                r ++;
            }
            else if(A[r+s+t] > pivot){
                D[s] = A[r+s+t];
                s ++;
            }
            else{
                t ++;
            }
        }
        if (r <= k && r + t > k){return pivot;}
        else if (r + t <= k){
            return quick_select(D,s,k-r-t);
        }
        else {
            return quick_select(C,r,k);
        }
    }
    
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
   printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
      return 0;
 }
    

