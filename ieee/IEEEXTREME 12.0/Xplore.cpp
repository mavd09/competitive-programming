#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e6 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

const string FULL_NAME = "full_name";
const string CITING_PAPER_COUNT = "citing_paper_count";

int n;
map<string, int> id;
string rid[MAXN], rid_m[MAXN];
vector<int> by_authors[MAXN];

bool cmp( const pii& a, const pii& b ) {
  if( a.second != b.second ) return a.second > b.second;
  return rid[a.first] < rid[b.first];
}

string get_name( string& line, int fr ) {
  fr += FULL_NAME.size() + 1;
  while( line[fr] != '"' ) fr++;
  fr++;
  int to = fr;
  while( line[to] != '"' ) to++;
  string name = line.substr(fr, to-fr);
  return name;
}

ll get_citations( string& line ) {
  ll r = 0;
  int fr = line.find(CITING_PAPER_COUNT);
  if( fr == -1 ) return 0;
  fr += CITING_PAPER_COUNT.size() + 1;
  while( !isdigit(line[fr]) ) fr++;
  while( isdigit(line[fr]) ) r = r*10 + (line[fr++]-'0');
  return r;
}

int get_id( string name ) {
  if( id.count(name) ) return id[name];
  int r = id.size();
  id[name] = r;
  rid[r] = name;
  return r;
}

int main() {

  string line; getline( cin, line );
  stringstream ss(line);
  ss >> n;

  for( int i = 0; i < n; ++i ) {
    string line; getline( cin, line );
    int citations = get_citations(line);
    int start = -1;
    while( (start = line.find(FULL_NAME,start+1)) != -1 ) {
      int idx = get_id( get_name(line, start) );
      by_authors[idx].push_back(citations);
    }
  }

  vector<pii> authors;
  for( int i = 0; i < id.size(); ++i ) {
    int h_index = 0;
    sort(by_authors[i].rbegin(), by_authors[i].rend());
    for( int j = 0; j < by_authors[i].size(); ++j ) {
      if( by_authors[i][j] >= j+1 ) {
        h_index = j+1;
      }
    }
    authors.push_back({i, h_index});
  }

  sort(authors.begin(), authors.end(), cmp);

  for( int i = 0; i < min(10, (int)authors.size()); ++i ) {
    cout << rid[authors[i].first] << ' ' << authors[i].second << endl;
  }

  return 0;
}