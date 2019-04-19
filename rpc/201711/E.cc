#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int arr[ 7 ];

int a[ 3 ], b[ 3 ];

bool play( int x, int* arr, int& idx, int& aux2 ) {
  int cnt = 0;
  for( int i = 0; i < 3; ++i ) {
    if( arr[i] == -1 ) continue;
    cnt += ( arr[i] < x );
  }
  idx = -1;
  if( cnt == 0 ) {
    for( int i = 0; i < 3; ++i ) {
      if( arr[i] == -1 ) continue;
      idx = i;
    }
  } else {
    for( int i = 0; i < 3; ++i ) {
      if( arr[i] == -1 || arr[i] > x ) continue;
      idx = i;
    }
  }
  aux2 = arr[idx];
  arr[idx] = -1;
  return cnt > 0;
}

bool dfs( int t, int w ) {
  if( t == 3 ) return w > 1;
  bool r = false;
  if( t&1 ) {
    r = true;
    for( int i = 0; i < 3; ++i ) {
      if( b[i] == -1 ) continue;
      int aux1 = b[i], idx, aux2; b[i] = -1;
      r &= dfs( t+1, w+play( aux1, a, idx, aux2 ) );
      b[i] = aux1; a[idx] = aux2; 
    }
  } else {
    for( int i = 0; i < 3; ++i ) {
      if( a[i] == -1 ) continue;
      int aux1 = a[i], idx, aux2; a[i] = -1;
      r |= !dfs( t+1, w+!play( aux1, b, idx, aux2 ) );
      a[i] = aux1; b[idx] = aux2;
    }
  }
  return r;
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

    
  while( cin >> arr[0] >> arr[1] >> arr[2] ) {
    for( int i = 3; i < 7; ++i ) {
      for( int j = 1; j <= 7; ++j ) {
        bool ok = true;
        for( int k = 0; k < i; ++k ) {
          ok &= j != arr[k];
        }
        if( ok ) {
          arr[i] = j;
        }
      }
    }
    sort( arr, arr+3 );
    sort( arr+3, arr+7 );
    for( int i = 0; i < 3; ++i ) {
      a[i] = arr[i];
      b[i] = arr[i+3];
    }
    bool ans = false;
    if( arr[0] == 1 && arr[1] == 2 ) ans = true;
    if( arr[0] == 1 && arr[1] == 3 ) ans = true;
    if( arr[0] == 1 && arr[1] == 4 && arr[2] == 5 ) ans = true;
    if( arr[0] == 2 && arr[1] == 3 && arr[2] == 4 ) ans = true;
    cout << "NS"[ans] << '\n';
  }

  return 0;
}

