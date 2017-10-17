#include<bits/stdc++.h>

using namespace std;

const int MAXN = 10;
const int oo = int(1e5);

int a[ MAXN ], b[ MAXN ];

int solve( int cur, int nxt ) {
  if( cur == 0 && nxt == 0 ) return 0;
  int final = -oo, score;
  for( int i = 1; i <= 7; ++i ) {
    if( cur&(1<<i) ) {
      score = oo;
      for( int j = 1; j <= 7; ++j ) {
        if( nxt&(1<<j) ) {
          if( i<j ) {
            score = min( score, 1+solve( cur^(1<<i), nxt^(1<<j) ) );
          }
          else {
            score = min( score, -1-solve( nxt^(1<<j), cur^(1<<i) ) );
          }
        }
      }
      final = max( final, score );
    }
  }
  return final;
}

int main() {

  freopen( "input", "r", stdin );

  //for( a[0] = 1; a[0] <= 7; ++a[0] )
  //for( a[1] = a[0]+1; a[1] <= 7; ++a[1] )
  //for( a[2] = a[1]+1; a[2] <= 7; ++a[2] ) {
    cin >> a[0] >> a[1] >> a[2];
    sort( a, a+3 );
    int cur = 0, nxt = 0;
    for( int i = 1, j = 0, k = 0; i <= 7; ++i ) {
      if( i == a[j] ) {
       ++j;
        cur |= (1<<i);
        continue;
      }
      if( ++k <= 3 ) {
        nxt |= (1<<i);
      }
    }
//     cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    if( solve(cur,nxt) > 0 ) cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
//    cout << "NS"[ solve( cur, nxt ) > 0 ] << '\n';
//  }
  return 0;
}
