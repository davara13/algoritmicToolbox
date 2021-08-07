#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int RQS(vector<int> &a, int r, int l, int n){
	if(l>=r){
		return 0;
	}
	/*else if(r-l<(n/2+1)){
		return 0;
	}*/
	int k = l + rand()%(r-l);
	int x = a[k];
	swap(&a[k],&a[l]);
	int pi=l;
	int si = pi + 1;
	int count = 1;
	
	for(int i = pi + 1 ; i<=r; i++){
		if(a[i]<x){
			swap(&a[si],&a[i]);
			si++;
		}
		if(a[i]==x){
			count++;
		}
		if(count>(int)(n/2)){
			return 1;
		}
	}
	swap(&a[si-1],&a[pi]);
	RQS(a,si-2,l,n);
	RQS(a,r,si,n);	
}

int get_majority_element(vector<int> &a, int left, int right) {
	int x = a[0];
	int c = 1;
	for(int i = 1; i<a.size(); i++){
		if(a[i]==x){
			c++;
		}else{
			if(c>(a.size()/2)){
				return 1;
			}else{
				c = 1;
				x=a[i];
			}	
		}
	}
	if(c >(a.size()/2)){
		return 1;
	}else{
		return 0;
	}
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(),a.end());
  
  std::cout<<get_majority_element(a, 0, a.size()-1);
}
