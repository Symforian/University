#include <iostream>
#include <vector>
#include <algorithm> 
#include <stack>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(true);
	int n, q; 
	cin>>n>>q;
	vector <pair<int,int> > parent_children;
	int buff;
    	for (int i=2; i<=n; i++)
{
	cin>>buff;
        parent_children.push_back( make_pair(buff,i) );
}

	sort(parent_children.begin(),parent_children.end());
	int last = n;
	int somsiad_array [last+1];
	somsiad_array[1]=1;
	int ptr = 1;
	for(int i = 2; i< n+1; i++)
		if(parent_children[i-1].first==ptr) continue;
		else
		{
			ptr++;
			if(parent_children[i-1].first==ptr) somsiad_array[ptr]=i;
			else if (parent_children[i-1].first>ptr)
			{
				somsiad_array[ptr]=-1;
				i--;
			}
		}
	
	for(int i = ptr; i<last+1; i++)
	somsiad_array[i]=-1;

	vector<bool> visited(last+1, false);
	vector<pair <int,int >> time(last+1, make_pair<int,int> (-1,-1));
	stack<int> stack;
 
	stack.push(1);
 	int T = 0;
	while (!stack.empty())
	{

		int s = stack.top();
		stack.pop();

		if (!visited[s])
		{
			visited[s] = true;
			time[s].first = T;
			T++;
			stack.push(s);
			if(somsiad_array[s]!=-1)
			{
				
				for (int i = somsiad_array[s]-1; i < last+1; ++i)
					{
						if(parent_children[i].first!= s) break;
						if (!visited[parent_children[i].second])
							stack.push(parent_children[i].second);
					}		
				
			}	
		}
		else time[s].second = T-1;
	}
	int a,b;
	for(int i =0; i<q; i++)
	{
		cin>>a;
		cin>>b;
		if((time[b]).first>= (time[a]).first 
		&& (time[b]).second<= (time[a]).second)
		cout<<"TAK\n";
		else cout<<"NIE\n";
	}

	return 0;
}
