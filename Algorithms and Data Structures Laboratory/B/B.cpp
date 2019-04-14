#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
typedef struct { std::pair<int,int> a, b; } parpar;
bool acompare( parpar a, parpar b) {return (a.a.first+a.a.second < b.a.first + b.a.second); }
int main(){
	std::ios::sync_with_stdio(true);
	std::map<std::pair<int,int>,int> node_map;
	node_map.insert(std::make_pair(std::make_pair(0,0),1));
	int m, n, t, a1,b1,a2,b2;
	std::cin>>m>>n>>t;
	node_map.insert(std::make_pair(std::make_pair(m,n),0));
	parpar a;
	std::vector <parpar> tunnels;
	for(int i =0; i < t; i++){
		std::cin>>a1>>b1>>a2>>b2;
		a.a = std::make_pair(a1,b1);
		a.b = std::make_pair(a2,b2);
		node_map.insert(std::make_pair(a.b,0));
		tunnels.push_back(a);}
	std::sort(tunnels.begin(),tunnels.end(),acompare);
	for(int i = 0 ; i< t; i++) node_map[tunnels[i].b]=(node_map[tunnels[i].b]+node_map[tunnels[i].a])%999979;
	std::cout<<node_map[std::make_pair(m,n)]<<"\n";
	return 0;}
