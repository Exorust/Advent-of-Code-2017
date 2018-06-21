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
  string reg,command,val,dump,cond_reg,cond_operator,cond_val;
  map<string, int> registers;
  while(infile>>reg && infile>>command && infile>>val && infile>>dump && infile>>cond_reg && infile>>cond_operator && infile>>cond_val ){
    if(registers.find(reg) == registers.end()) {
      registers.insert(pair<string,int>(reg,0));
    }
    if(registers.find(cond_reg) == registers.end()) {
      registers.insert(pair<string,int>(cond_reg,0));
    }
    bool check = false;
    int reg_value = registers.find(cond_reg)->second;
    int cond_value =stoi(cond_val);
    int value =stoi(val);
    // cout<<value<<" "<<cond_value;

    if(cond_operator == "==" && reg_value == cond_value){
      check = true;
    }
    else if(cond_operator == ">=" && reg_value >= cond_value) {
      check = true;
    }
    else if(cond_operator == "<=" && reg_value <= cond_value) {
      check = true;
    }
    else if(cond_operator == ">" && reg_value > cond_value) {
      check = true;
    }
    else if(cond_operator == "<" && reg_value < cond_value) {
      check = true;
    }
    else if(cond_operator == "!=" && reg_value != cond_value) {
      check = true;
    }
    map<string,int>::iterator it = registers.find(reg);
    reg_value = it->second;
    if (check == true) {
      registers.erase(it);
      if(command =="inc")
        registers.insert(pair<string,int>(reg,reg_value+value));
      else if(command =="dec")
        registers.insert(pair<string,int>(reg,reg_value-value));
    }
  }
  int max = 0;
  for(map<string,int>::iterator it = registers.begin();it != registers.end();it++) {
    if(max<it->second){
      max = it->second;
    }
  }
  cout<<max;

	return 0;
}
