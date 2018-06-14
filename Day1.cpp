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
  char c;
  int prev=0;
  int sum=0;
  infile.get(c);
  int first= (int)(c) - 48;
  int x=0;
  while(infile.get(c) && c !='\n'){
    x = (int)c;
    x-=48;
    if(x == prev) {
      sum+=prev;
    }
    prev = x;
  }
  if(first == x){
    sum +=x;
  }

  cout<<sum;

	return 0;
}
