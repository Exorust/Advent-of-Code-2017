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
  int r_large=0,r_small=9999999,sum=0;
  char c;
  int x=0;
  while(infile.get(c)){
    if(c=='\n'){
      sum += (r_large-r_small);
      cout<<r_large<<" "<<r_small<<endl;
      x=0;
      r_large=0;
      r_small=9999999;
    }
    else if(c == '\t' || c==' '){
      if(x>r_large){
        r_large = x;
      }
      if(x<r_small){
        r_small = x;
      }
      x=0;
    }
    else{
      int z =(int)c;
      z-=48;
      x = x*10+z;
    }
  }

  cout<<sum<<endl;
	return 0;
}
