#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 1e2+50 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int m, last;
double months, downPay, amount, depRec, dep;
double depMonth[ MAXN ];

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> months ) && ( months > 0 ) ) {
        cin >> downPay >> amount >> depRec;
        last = -1;
        for( int i = 0; i < MAXN; i++ ) depMonth[ i ] = -1.0;
        for( int i = 0; i < depRec; i++ ) {
            cin >> m >> dep;
            depMonth[ m ] = dep;
        }
        for( int i = 1; i < MAXN; i++ ) {
            if( depMonth[ i ] == -1.0 ) {
                depMonth[ i ] = depMonth[ i-1 ];
            }
        }
        double penPay = amount, curVal = amount+downPay;
        int curMonth = 0;
        while( true ) {
            curVal *= ( 1.0-depMonth[ curMonth ] );
            if( penPay < curVal ) break;
            penPay -= amount/months;
            curMonth++;
        }
        if( curMonth == 1 ) cout << "1 month\n";
        else cout << curMonth << " months\n";
    }

    return 0;
}
