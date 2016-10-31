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

const double PI = acos( -1.0 );
const double eps = 1e-9;

struct Data { int DD, MM, YYYY, hh, mm; double lat, lon; };

Data get_best( Data a, Data b ) {
  if( a.YYYY != b.YYYY ) {
    if( a.YYYY < b.YYYY ) {
      return b;
    }
    return a;
  }
  if( a.MM != b.MM ) {
    if( a.MM < b.MM ) {
      return b;
    }
    return a;
  }
  if( a.DD != b.DD ) {
    if( a.DD < b.DD ) {
      return b;
    }
    return a;
  }
  if( a.hh != b.hh ) {
    if( a.hh < b.hh ) {
      return b;
    }
    return a;
  }
  if( a.mm != b.mm ) {
    if( a.mm < b.mm ) {
      return b;
    }
    return a;
  }
  return a;
}

void modify_str( string& s ) {
  for( auto& c : s ) {
    if( c == '/' || c == ':' || c == ',' ) {
      c = ' ';
    }
  }
}

double to_deg( double in_rad ) {
  return in_rad*180.0/PI;
}

double to_rad( double in_deg ) {
  return in_deg*PI/180.0;
}

double sqr( double x ) {
  return x*x;
}

double get_dist( double lat1, double lon1, double lat2, double lon2 ) {
  return 2.0*6378.137*( asin( sqrt( sqr( sin( to_rad( ( lat1-lat2 )/2.0 ) ) ) + cos( to_rad( lat1 ) ) * cos( to_rad( lat2 ) ) * sqr( sin( to_rad( ( lon1-lon2 )/2.0 ) ) ) ) ) );
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

  map< ll, Data > data;
  string line;
  ll id;
  int DD, MM, YYYY, hh, mm;
  double lat, lon, LAT, LON;

  cin >> line; modify_str( line );
  stringstream ss( line );
  ss >> LAT >> LON;
  double r; cin >> r; cin.ignore( );
  getline( cin, line );
  while( getline( cin, line ) ) {
    modify_str( line );
    stringstream ss( line );
    ss >> MM >> DD >> YYYY >> hh >> mm >> lat >> lon >> id;
    Data new_data = { DD, MM, YYYY, hh, mm, lat, lon };
    if( data.count( id ) ) {
      data[ id ] = get_best( data[ id ], new_data );
    }
    else {
      data[ id ] = new_data;
    }
  }

  vll ans;
  for( auto& e : data ) {
    //cout << e.first << " " << e.second.MM << "/" << e.second.DD << "/" << e.second.YYYY << " " << e.second.hh << ":" << e.second.mm << "\n"; 
    //cout << get_dist( LAT, LON, e.second.lat, e.second.lon ) << endl;
    if( r-get_dist( LAT, LON, e.second.lat, e.second.lon ) > eps ) {
      ans.PB( e.first );
    }
  }

  for( int i = 0; i < int( ans.size( ) ); i++ ) {
    if( i ) {
      cout << ",";
    }
    cout << ans[ i ];
  }
  cout << "\n";

  return 0;
}