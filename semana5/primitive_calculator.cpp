#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
 	vector<int> v(n+1, 0);
    vector<int> result;
    result.push_back(n);
    v[0]=1;v[1]=0;
    int t;
    for(int i=2; i<n+1;i++){
        t=n+1;
        if(i%3==0){
            t=v[i/3]+1;
        }
        if(i%2==0){
            if((v[i/2]+1)<t){
                t=v[i/2]+1;
            }
        }
        if((v[i-1]+1)<t){
            t=v[i-1]+1;
        }
        v[i]=t;
    }
    int m=n;
    int t2;
    while(m!=1){
        t=m+1;
        if(m%3==0){
            t=v[m/3]+1;
            t2=m/3;
        }
        if(m%2==0){
            if((v[m/2]+1)<t2){
                t=v[m/2]+1;
                t2=m/2;
            }
        }
        if((v[m-1]+1)<t){
            t=v[m-1]+1;
            t2=m-1;
        }
        result.push_back(t2);
        m=t2;
    }
    //*/
    reverse(result.begin(), result.end());
    return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
