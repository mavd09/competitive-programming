#include <bits/stdc++.h>

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     2100
#define MOD     1000000007LL

#define INF     ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct State {
    
    int compliance, id;
    double price;
    string name;
    
    State( ) { }
    State( int id, string name, int compliance, double price ) : id( id ), name( name ), compliance( compliance ), price( price ) { }
    
};

struct cmp {
    
    bool operator ( ) ( const State &a, const State &b ) {
        if( a.compliance != b.compliance ) return a.compliance < b.compliance;
        if( a.price != b.price ) return a.price > b.price;
        return a.id > b.id;
    }
    
};

int n, p;
string line;

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    for( int tc = 1; ( cin >> n >> p ) && ( n+p > 0 ); tc++ ) {
        cin.ignore( );
        for( int i = 0; i < n; i++ ) getline( cin, line );
        priority_queue< State, vector< State >, cmp > q;
        for( int i = 0; i < p; i++ ) {
            State cur;
            getline( cin, cur.name );
            cin >> cur.price >> cur.compliance;
            cur.id = i;
            cin.ignore( );
            for( int j = 0; j < cur.compliance; j++ ) getline( cin, line );
            q.push( cur );
        }
        if( tc > 1 ) cout << "\n";
        cout << "RFP #" << tc << "\n" << q.top( ).name << "\n";
    }
    
    return 0;
    
}