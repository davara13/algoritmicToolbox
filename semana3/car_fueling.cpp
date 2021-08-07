#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops, int n) {
	
	int nR = 0, cR = 0 , lR;
	while(cR<=n){
		lR = cR;
		while(cR<=n && (stops[cR+1]-stops[lR])<=tank){
			//cout<<"cR = "<<cR<<"resta= "<<(stops[cR+1]-stops[lR])<<"\n";
			cR++;
		}
		if(cR==lR){
			return -1;
		}
		if(cR<=n){
			nR++;
			//cout<<"entre,  ultimo refill = "<<cR<<" ultimo refill = "<<lR<<std::endl;
		}
	}
	
    return nR;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);
	//cout<<"capacidad = "<<stops.capacity()<<"\n";
	stops[n+1]=d;
	stops[0]=0;
/*	for(int i = 0; i<n+2; i++){
		cout<<"i = "<<stops[i]<<"\n";
	}*/
    cout << compute_min_refills(d, m, stops,n) << "\n";

    return 0;
}
