#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition3(vector<int> &a, int l, int r) {
  	int x = a[l];
  	int lt = l;
 	int gt = r;
 	int i = lt+1;
  	while(i<=gt){
    	if (a[i] < x) {
      		swap(a[lt], a[i]);
      		lt++;
      		i++;
    	}else if(a[i]>x){
    		swap(a[gt], a[i]);
      		gt--;
		}else if(a[i]==x){
			i++;
		}
  	}
  	
  	vector<int> par;
  	par.push_back(lt);
  	par.push_back(gt);
  	return par;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  
  int k = l + rand()%(r-l+1);
  swap(a[k],a[l]);
  
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
