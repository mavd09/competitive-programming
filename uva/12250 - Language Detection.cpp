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
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

string word[ ]     = { "HELLO"  , "HOLA"   , "HALLO" , "BONJOUR", "CIAO"   , "ZDRAVSTVUJTE" };
string language[ ] = { "ENGLISH", "SPANISH", "GERMAN", "FRENCH" , "ITALIAN", "RUSSIAN"      };
string w;
int t;

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> w ) && ( w != "#" ) ) {
        bool found = false;
        for( int i = 0; i < 6; i++ ) {
            if( word[ i ] == w ) {
                cout << "Case " << ++t << ": " << language[ i ] << "\n";
                found = true;
            }
        }
        if( !found ) cout << "Case " << ++t << ": UNKNOWN\n";
    }

    return 0;
}
