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
  int current_score = 0;
  int sum =0;
  char c,dump;
  while(infile.get(c) ){
    if(c == '{') {
      current_score++;
    }
    else if(c == '<') {
      while(infile.get(dump)) {
        if(dump == '!') {
          infile.get(dump);
        }
        else if(dump == '>') {
          break;
        }
      }
    }
    else if(c == '!') {
      infile.get(dump);
    }
    else if(c == '}') {
      sum += current_score;
      current_score--;
    }

    if(c =='\n') {
      break;
    }
    if(current_score ==0){
      break;
    }
    cout<<c;
  }
  cout<< sum;

	return 0;
}
