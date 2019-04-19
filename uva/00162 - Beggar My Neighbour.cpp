#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MOD1    256
#define MOD2    100

#define INF     ( 1<<29 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    map< char, int > faceCard;

    faceCard[ 'J' ] = 2;
    faceCard[ 'Q' ] = 3;
    faceCard[ 'K' ] = 4;
    faceCard[ 'A' ] = 5;

    while( true ) {
        int player = 1, pending = 0, lastPlayer;
        deque< string > st[ 2 ], deck;
        string card;
        for( int i = 1; i <= 52; i++, player = 1-player ) {
            cin >> card;
            if( card == "#" ) return 0;
            st[ player ].push_back( card );
        }

        while( !st[ player ].empty( ) ) {
            card = st[ player ].back( ); st[ player ].pop_back( );
            deck.push_back( card );
            if( faceCard.count( card[ 1 ] ) ) {
                pending = faceCard[ card[ 1 ] ];
                lastPlayer = player;
                player = 1-player;
            }
            if( pending ) {
                if( --pending == 0 ) {
                    player = lastPlayer;
                    while( !deck.empty( ) ) {
                        st[ player ].push_front( deck.front( ) );
                        deck.pop_front( );
                    }
                }
            }
            else player = 1-player;
        }

        cout << ( 1-player+1 );
        cout.width( 3 );
        cout << right << int( st[ 1-player ].size( ) ) << "\n";
    }

    return 0;
}
