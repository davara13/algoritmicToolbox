#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
  double V = 0.0;
  double W = capacity;
  double vs[n];

  for(int  i = 0; i<n ; i++){
  	vs[i] = (double)values[i] / (double)weights[i]; 
  }
  
  if(n==1){
  	if(weights[0]<=W){
  		return vs[0]*weights[0];
	  }else{
	  	return vs[0]*W;
	  }
  }
  
  while(W > 0){
  	int mayor = 0;
  	for(int j = 1; j<n; j++){
  		if(vs[j]>vs[mayor]){
  			mayor = j;
		}
	}
	if(weights[mayor]>W){
		V = V + vs[mayor]*W;
		W = 0;
		vs[mayor] = -1;
	}else{
		V = V + vs[mayor]*weights[mayor];
		W = W - weights[mayor];
		vs[mayor] = -1;
	}
  }
  

  return V;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values,n);

  std::cout.precision(14);
  std::cout << optimal_value << std::endl;
  return 0;
}
