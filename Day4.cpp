#include <bits/stdc++.h>

 #define all(c) c.begin(), c.end()
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream infile;
  infile.open("inp");
  string s;
  char c;
  set<string> us;
  int count=0;
  int internal_count=0;
  while(infile.get(c) ){
    if(c =='\n') {
      us.insert(s);
      internal_count++;
      s.clear();
      if(internal_count == us.size()) {
        count++;
      }
      internal_count=0;
      us.clear();
    }
    else if(c=='\t' || c==' ') {
      us.insert(s);
      s.clear();
      internal_count++;
    }
    else {
      s.push_back(c);
    }
  }
  cout<<count<<endl;

	return 0;
}
