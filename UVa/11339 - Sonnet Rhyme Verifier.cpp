#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define MAXS    5
#define MAXN    int( 1e5+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

string validRhymes[ ] = { "ABBAABBACDECDE", "ABBAABBACDEDCE", "ABBAABBACDCDCD" };
string line, title, rhyme, s[ MAXS ], sonnet[ MAXN ];
int sz, szs;
bool can;

void cleanVersion( ) {
    for( int i = 0; i < sz; i++ ) {
        int cursz = int( sonnet[ i ].size( ) );
        string tmp = "";
        for( int j = 0; j < cursz; j++ ) {
            char c = sonnet[ i ][ j ];
            if( c == '¡' || c == '¿' || c == '!' || c == ',' || c == '.' || c == ':' || c == ';' || c == '?' || c == '-' )
                continue;
            tmp += c;
        }
        sonnet[ i ] = tmp;
        cursz = int( sonnet[ i ].size( ) );
        while( cursz && ( sonnet[ i ][ cursz-1 ] == 's' || sonnet[ i ][ cursz-1 ] == ' ' ) ) sonnet[ i ].erase( --cursz );
    }
}

string findRhyme( ) {
    string curRhyme = "";
    for( int i = 0; i < sz; i++ ) {
        for( int j = 0; j < szs; j++ ) {
            int ks = int( s[ j ].size( ) )-1, k = int( sonnet[ i ].size( ) )-1;
            while( ks >= 0 && k >= 0 && sonnet[ i ][ k ] == s[ j ][ ks ] ) k--, ks--;
            if( ks == -1 ) curRhyme += 'A'+j;
        }
    }
    return curRhyme;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( getline( cin, line ) ) {
        stringstream ss( line );
        for( szs = 0; ss >> s[ szs ]; szs++ );
        getline( cin, title );
        for( sz = 0; getline( cin, sonnet[ sz ] ) && int( sonnet[ sz ].size( ) ); sz++ );
        can = ( sz == 14 );
        if( sz == 14 ) {
            cleanVersion( );
            rhyme = findRhyme( );
            can = false;
            for( int i = 0; i < 3; i++ ) can |= ( rhyme == validRhymes[ i ] );
        }

        if( can ) cout << title << ": " << rhyme << "\n";
        else      cout << title << ": Not a chance!\n";
    }

    return 0;
}
