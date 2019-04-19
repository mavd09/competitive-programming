#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <algorithm>
#include <limits.h>
#include <iomanip>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cassert>

#include <unordered_map>
#include <time.h>

#include <complex>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< vb >        vvb;
typedef vector< lf >        vd;
typedef vector< vd >        vvd;
typedef vector< vvd >       vvvd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;
typedef vector< vvi >       vvvi;
typedef vector< vvvi >      vvvvi;
typedef vector< pii >       vpii;
typedef vector< vpii >      vvpii;

typedef complex< lf >       pt;

const int MX  = 123;
const int MOD = int( 360 );
const int oo  = int( 2e9 );

int T;
clock_t t;

vvi id( 5, vi( 5 ) );

bool is_on( int& aa, int i ) {
  return ( aa>>i )&1;
} 

void change_bit( int& aa, int i ) {
  aa ^= ( 1<<i );
}

int flip_h( int aa, int x, int y, int n ) {
  int a, b;
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j*2 < n; j++ ) {
      a = is_on( aa, id[ x+i ][ y+j ] );
      b = is_on( aa, id[ x+i ][ y+( n-j-1 ) ] );
      if( ( a && !b ) || ( !a && b ) ) {
        change_bit( aa, id[ x+i ][ y+j ] );
        change_bit( aa, id[ x+i ][ y+( n-j-1 ) ] );
      }
    }
  }
  return aa;
}

int flip_v( int aa, int x, int y, int n ) {
  int a, b;
  for( int i = 0; i*2 < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      a = is_on( aa, id[ x+i ][ y+j ] );
      b = is_on( aa, id[ x+( n-i-1 ) ][ y+j ] );
      if( ( a && !b ) || ( !a && b ) ) {
        change_bit( aa, id[ x+i ][ y+j ] );
        change_bit( aa, id[ x+( n-i-1 ) ][ y+j ] );
      }
    }
  }
  return aa;
}

int neg( int aa, int x, int y, int n ) {
  int a, b;
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      change_bit( aa, id[ x+i ][ y+j ] );
    }
  }
  return aa;
}

struct State { int a, c, d; };
struct Cmp_State {
  bool operator( ) ( const State& x, const State& y ) {
    return x.d*x.c > y.d*y.c;
    if( x.c != y.c ) {
      return x.c > y.c;
    }
    return x.d > y.d;
  }
};

int go( int a, int b ) {
  unordered_map< int, int > mn;
  priority_queue< State, vector< State >, Cmp_State > pq;
  pq.push( { a, __builtin_popcount( a^b ), 0 } );
  mn[ a ] = 0;
  int na, d;
  int best = oo;
  while( !pq.empty( ) ) {
    if( lf( clock( )-t )/CLOCKS_PER_SEC*1000 > T ) {
      return best;
    } 
    State cur = pq.top( ); pq.pop( );
    //cout << cur.c << endl;
    a = cur.a;
    d = cur.d;
    if( d >= best || mn[ a ] != d ) {
      continue;
    }
    if( a == b ) {
      best = min( best, d );
      continue;
    }
    for( int i = 0; i < 5; i++ ) {
      for( int j = 0; j < 5; j++ ) {
        for( int k = 1; k <= 5; k++ ) {
          if( i+k <= 5 && j+k <= 5 ) {
            na = flip_h( a, i, j, k );
            if( !mn.count( na ) || d+1 < mn[ na ] ) {
              mn[ na ] = d+1;
              pq.push( { na, __builtin_popcount( na^b ), d+1 } );
            }
            na = flip_v( a, i, j, k );
            if( !mn.count( na ) || d+1 < mn[ na ] ) {
              mn[ na ] = d+1;
              pq.push( { na, __builtin_popcount( na^b ), d+1 } );
            }
            na = neg( a, i, j, k );
            if( !mn.count( na ) || d+1 < mn[ na ] ) {
              mn[ na ] = d+1;
              pq.push( { na, __builtin_popcount( na^b ), d+1 } );
            }
          }
        }
      }
    }
  }
  return best;
}

void print( int aa ) {
  for( int i = 0; i < 5; i++ ) {
    for( int j = 0; j < 5; j++ ) {
      cout << ( ( aa>>id[ i ][ j ] )&1 );
    }
    cout << "\n";
  }
  cout << endl;
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #endif

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  for( int i = 0; i < 5; i++ ) {
    for( int j = 0; j < 5; j++ ) {
      id[ i ][ j ] = i*5+j;
    }
  }

  int n_test; cin >> n_test;
  T = 1650/n_test;
  while( n_test-- ) {
    t = clock( );
    vector< string > a( 5 ), b( 5 );
    for( int i = 0; i < 5; i++ ) {
      cin >> a[ i ] >> b[ i ];
    }
    int aa = 0, bb = 0;
    for( int i = 0; i < 5; i++ ) {
      for( int j = 0; j < 5; j++ ) {
        if( a[ i ][ j ] == 'X' ) {
          aa |= ( 1<<id[ i ][ j ] );
        }
        if( b[ i ][ j ] == 'X' ) {
          bb |= ( 1<<id[ i ][ j ] );
        }
      }
    }/*
    print( aa );
    aa = flip_v( aa, 1, 1, 4 );
    print( aa );
    aa = flip_h( aa, 0, 0, 4 );
    print( aa );
    aa = flip_v( aa, 2, 0, 3 );
    print( aa );
    aa = neg( aa, 1, 0, 3 );
    print( aa );
    cout << aa << " " << bb << "\n";
    break;*/
    cout << go( aa, bb ) << "\n";
  }

  return 0;
}