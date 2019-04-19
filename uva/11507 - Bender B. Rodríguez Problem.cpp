#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     1001000

#define INF     ( 1LL<<60 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    int L;
    string cmd;

    while( ( cin >> L ) && ( L > 0 ) ) {
        string state = "+x";
        for( int i = 1; i < L; i++ ) {
            cin >> cmd;
            if( cmd == "No" ) continue;
            if( cmd == "+y" ) {
                if( state == "+x" )      state = "+y";
                else if( state == "-x" ) state = "-y";
                else if( state == "+y" ) state = "-x";
                else if( state == "-y" ) state = "+x";
                else if( state == "+z" ) state = "+z";
                else if( state == "-z" ) state = "-z";
            }
            if( cmd == "-y" ) {
                if( state == "+x" )      state = "-y";
                else if( state == "-x" ) state = "+y";
                else if( state == "+y" ) state = "+x";
                else if( state == "-y" ) state = "-x";
                else if( state == "+z" ) state = "+z";
                else if( state == "-z" ) state = "-z";
            }
            if( cmd == "+z" ) {
                if( state == "+x" )      state = "+z";
                else if( state == "-x" ) state = "-z";
                else if( state == "+y" ) state = "+y";
                else if( state == "-y" ) state = "-y";
                else if( state == "+z" ) state = "-x";
                else if( state == "-z" ) state = "+x";
            }
            if( cmd == "-z" ) {
                if( state == "+x" )      state = "-z";
                else if( state == "-x" ) state = "+z";
                else if( state == "+y" ) state = "+y";
                else if( state == "-y" ) state = "-y";
                else if( state == "+z" ) state = "+x";
                else if( state == "-z" ) state = "-x";
            }
        }
        cout << state << "\n";
    }

    return 0;
}
