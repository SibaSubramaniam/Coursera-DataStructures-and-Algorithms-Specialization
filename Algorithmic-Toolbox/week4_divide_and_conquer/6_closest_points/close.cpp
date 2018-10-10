#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

struct point{
	long long x;
	long long y;
};

bool comparator_y(struct point a,struct point b){
	return a.y<b.y;
}

bool comparator_x(struct point a,struct point b){
	return a.x<b.x;
}

long double distance(long long x1,long long y1,long long x2,long long y2){
	return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}

long double bruteforce(point p[],long long n){
	long double min_dist=999999;
	long double d=0.0;
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n;j++){
			d=distance(p[i].x,p[i].y,p[j].x,p[j].y);
			if(d<min_dist)
				min_dist=d;
		}
	}
	return min_dist;
}

long double strip_dist(point s[],long long n,long double d){
	long double min_dist=d;
	long double dist=0.0;
	sort(s,s+n,comparator_y);
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n && s[j].y-s[i].y<min_dist;j++){
			dist=distance(s[i].x,s[i].y,s[j].x,s[j].y);
			if(dist<min_dist)
				min_dist=dist;
		}
	}
	return min_dist;
}

long double divider(point p[],long long n){
	if(n<=2)
		return bruteforce(p,n);
	long long mid=n/2;
	point midpoint=p[mid];
	long double d1=divider(p,mid);
	long double d2=divider(p+mid,n-mid);
	long double d=min(d1,d2);

	point strip[n];
	long long j=0;
	for(long long i=0;i<n;i++){
		if(abs(p[i].x-midpoint.x)<d)
			strip[j++]=p[i];
	}
	return min(d,strip_dist(strip,j,d));
}

long double closest_point(point p[],long long n){
	sort(p,p+n,comparator_x);
	return divider(p,n);
}

int main(){
	long long n;
	cin>>n;
  	point p[n];
  	for (size_t i = 0; i < n; i++) {
    	cin >> p[i].x >> p[i].y;
  	}
	std::cout << std::fixed;
  	std::cout << std::setprecision(10) << closest_point(p, n) << "\n";
  	}