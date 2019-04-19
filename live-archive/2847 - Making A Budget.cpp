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

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef unsigned long long  ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< double >    vd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;

const int MAX = int( 1e5+1 );
const int MOD = int( 1e9+7 );
const ll  oo  = LLONG_MAX-100LL+LLONG_MAX;

int n_months;
ll hire, salary, severance;
int max_workers;
vi workers_per_month;
map< pll, ll > dp;

ll go( int month, int workers ) {
  if( month == n_months )
    return 0;
  pll state = make_pair( month, workers );
  if( dp.count( state ) ) {
    return dp[ state ];
  }
  ll r = oo;
  int mn = max( 0, workers_per_month[ month ]-workers );
  for( int i = 0; workers+mn+i <= max_workers; i++ ) {
    ll tmp = go( month+1, workers+mn+i );
    if( tmp != oo ) {
      r = min( r, tmp+ll( mn+i )*hire+ll( workers+mn+i )*salary );
    }
  }
  if( !mn ) {
    for( int i = 0; workers_per_month[ month ] <= workers+i; i-- ) {
      ll tmp = go( month+1, workers+i );
      if( tmp != oo ) {
        r = min( r, tmp+ll( -i )*severance+ll( workers+i )*salary );
      }
    }
  }
  return dp[ state ] = r;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  for( int tc = 1; ( cin >> n_months ) && ( n_months > 0 ); tc++ ) {
    cin >> hire >> salary >> severance;
    workers_per_month.resize( n_months );
    for( auto& e : workers_per_month ) {
      cin >> e;
      max_workers = max( max_workers, e );
    }
    dp.clear( );
    cout << "Case " << tc << ", cost = $" << go( 0, 0 ) << "\n";
  }

  return 0;
}