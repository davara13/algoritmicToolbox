#include <iostream>

int get_change(int m) {
  int coins[3]={1,3,4};
  int MNC [m+1];
  MNC[0]=0;
  int NC = 0;
  for(int i = 1; i<=m; i++){
  	MNC[i]=2000;
  	for(int j = 0; j<3; j++){
  		if (i>=coins[j]){
  			NC = MNC[i-coins[j]]+1;
  			if(NC<MNC[i]){
  				MNC[i]=NC;
			  }
		  }
	  }
  } 
  
  return MNC[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
