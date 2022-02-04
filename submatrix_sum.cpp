#include<bits/stdc++.h>

using namespace std;

int main() {

  int N, M, Q;
  cin >> N >> M;
  int A[N][M];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> A[i][j];
  cin >> Q;

  while (Q--) {
    int x1, y1, x2, y2 ;
    cin >> x1 >> y1 >> x2 >> y2;

    int sum = 0;
    for (int i = x1 - 1 ; i < x2; i++) 
      for (int j = y1 - 1; j < y2; j++)
        sum += A[i][j];
        
    cout << sum << "\n";
  }

  return 0;
}