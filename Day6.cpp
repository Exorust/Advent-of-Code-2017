#include <bits/stdc++.h>
#include <unordered_set>

 #define all(c) c.begin(), c.end()
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

using namespace std;

int find_max(const vector<int>& v ){
  int max=0;
  for(int i=0;i<v.size();i++) {
    if(v[max]<v[i]) {
      max = i;
    }
  }
  return max;
}

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
  for(int j=0;j<v.size();j++) {
    cout<<v[j]<<" ";
  }
  cout<<endl;

  set<vector<int> > us;

  int hello=0;
  while(++hello){
    int max_index=find_max(v);
    int z = v[max_index];
    v[max_index] = 0;
    for(i=(max_index+1)%v.size();z>0;i=(i+1)%v.size()){
      v[i]++;
      z--;
    }
    for(int j=0;j<v.size();j++) {
      cout<<v[j]<<" ";
    }
    cout<<endl;
    set<vector<int> >::iterator it = us.find(v);
    if(it != us.end()) {
      break;
    }
    else {
      vector<int>* v2 = new vector<int>(v.begin(),v.end());
      us.insert(*v2);
    }
  }

  cout<<hello<<endl;

	return 0;
}
