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
  vector<int> v;
  int i;
  while(infile>>i){
    v.push_back(i);
  }

  i=0;
  int steps=0;
  int n = v.size();
  while(i<n && i>=0 ) {
    int j =i;
    i +=v[i];
    v[j]++;
    steps++;
  }
  cout<<steps;
	return 0;
}
