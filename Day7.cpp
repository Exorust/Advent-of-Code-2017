#include <bits/stdc++.h>

 #define all(c) c.begin(), c.end()
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

void resize(int** arr, int old_size,int new_size) {
  int** arrt;
  arrt = (int**)realloc(arr,new_size*sizeof(int*));
  arr = arrt;
  int* arrtemp;
  for(int i=0;i<old_size;i++){
    arrtemp = (int*)realloc(arr[i],new_size*sizeof(int));
    arr[i] = arrtemp;
    for(int j=old_size;j<new_size;j++){
      arr[i][j] = 0;
    }
  }
  for(int i=old_size;i<new_size;i++) {
    arr[i] = (int*)malloc(new_size*sizeof(int));
    for(int j=0;j<new_size;j++){
      arr[i][j] = 1;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ifstream infile;
  infile.open("inp");

  string s;
  string dump;
  int count=0;
  string prev;

  map<string,int> mp;
  int** arr = (int**)malloc(1*1*sizeof(int*));
  arr[0] = (int*)malloc(sizeof(int));
  int size = 1;
  size++;
  resize(arr,size-1,size);


  while(infile>>s ){
    if(s.compare("->") == 0){
      infile>>s;
      while(s.at(s.size()-1) ==','){
        s.erase(s.size()-1,1);
        map<string,int>::iterator it = mp.find(s);
        if(it == mp.end()){
          mp.insert(pair<string,int>(s,mp.size()+1));
          size++;
          resize(arr,size-1,size);
        }
        int i = (mp.find(s))->second;
        int j = (mp.find(prev))->second;
        arr[i][j]=1;
        infile>>s;
      }
      map<string,int>::iterator it = mp.find(s);
      if(it == mp.end()){
        mp.insert(pair<string,int>(s,mp.size()+1));
        size++;
        resize(arr,size-1,size);
      }
      int i = (mp.find(s))->second;
      int j = (mp.find(prev))->second;
      arr[i][j]=1;

    }
    else{
      infile>>dump;
      map<string,int>::iterator it = mp.find(s);
      if(it == mp.end()){
        mp.insert(pair<string,int>(s,mp.size()+1));
        size++;
        resize(arr,size-1,size);
      }
      prev.swap(s);
    }
  }

  int a = rand()*size;
  int b = rand()*size;

  int x,y;
  int z = size;
  while(z--){
    for(int m=0;m<size;m++){
      if(arr[a][m] ==1){
        a=m;
      }
    }
  }

  map<string,int>::iterator it=mp.begin();
  for(int i=0;i<=a;i++){
    it++;
  }
  cout<<it->second;

	return 0;
}
