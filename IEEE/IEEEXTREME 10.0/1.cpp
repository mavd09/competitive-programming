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

string COLOR = "rgb";

struct Condition { int t, a, b; };

int n, k;
vector< vector< Condition > > condition( 20 );
vi ans( 10 ), color( 10 ), count_color( 3 ), answer( 20 );
vb is_and( 20 );

int get_id_color( char c ) {
  if( c == 'r' ) {
    return 0;
  }
  if( c == 'g' ) {
    return 1;
  }
  return 2;
}

bool evaluate_condition( int id ) {
  int total_true = 0, total = 0;
  for( auto& c : condition[ id ] ) {
    total++;
    if( ( c.t == 0 && count_color[ c.a ] == c.b ) || ( c.t == 1 && color[ c.a ] == c.b ) ) {
      total_true++;
    }
    if( !is_and[ id ] && total_true != 0 ) {
      break;
    }
    if( is_and[ id ] && total_true != total ) {
      break;
    }
  }
  bool ret = true;
  if( is_and[ id ] && total_true != total ) {
    ret = false;
  }
  if( !is_and[ id ] && total_true == 0 ) {
    ret  = false;
  }
  if( answer[ id ] == 1 ) {
    return ( ret == true );
  }
  return ( ret == false );
}

void evaluate( ) {
  int fails = 0;
  for( int i = 0; i < n; i++ ) {
    fails += !evaluate_condition( i );
    if( fails > k ) {
      return ;
    }
  }
  if( fails == k ) {
    for( int i = 0; i < 10; i++ ) {
      ans[ i ] = ans[ i ]|( 1<<color[ i ] );
    }
  }
}

void go( int id ) {
  if( id == 10 ) {
    evaluate( );
    return ;
  }
  for( int new_color = 0; new_color < 3; new_color++ ) {
    color[ id ] = new_color;
    count_color[ new_color ]++;
    go( id+1 );
    count_color[ new_color ]--;
  }
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  int n_test; cin >> n_test;

  string cmd;
  int t, a, b; char d;

  for( int tc = 1; n_test--; tc++ ) {
    cin >> n >> k;
    for( int i = 0; i < n; i++ ) {
      condition[ i ].clear( );
      while( cin >> cmd ) {
        if( cmd == "count" ) {
          t = 0;
          cin >> d >> b;
          a = get_id_color( d );
        }
        else {
          t = 1;
          cin >> a >> d;
          a--;
          b = get_id_color( d );
        }
        condition[ i ].PB( { t, a, b } );
        cin >> cmd;
        if( cmd == "yes" || cmd == "no" ) {
          if( cmd == "yes" ) {
            answer[ i ] = 1;
          }
          else {
            answer[ i ] = 0;
          }
          break;
        }
        else {
          if( cmd == "and" ) {
            is_and[ i ] = true;
          }
          else {
            is_and[ i ] = false;
          }
        }
      }
    }
    go( 0 );
    for( int i = 0; i < 10; i++ ) {
      if( i ) {
        cout << " ";
      }
      for( int j = 0; j < 3; j++ ) {
        if( ( ans[ i ]>>j )&1 ) {
          cout << COLOR[ j ];
        }
      }
      ans[ i ] = 0;
    }
    cout << "\n";
  }

  return 0;
}