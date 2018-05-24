#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> vi;
	for(int i=0; i<10; i++)
		vi.push_back(i);

	vi.push_back(9);
	vi.push_back(9);

	for(auto& v : vi)
		cout << v << "\t" ;
	cout << endl;

	for(auto p = vi.begin(); p!=vi.end(); ++p){
		if(p!=vi.begin() && *(p-1)==*p)
			cout << "duplicate " << *p << endl;
	}

	vi.pop_back();
	vi.pop_back();
	vi.pop_back();
	vi.pop_back();

	for(auto& v : vi)
		cout << v << "\t" ;
	cout << endl;

	vi.emplace_back(1);
	vi.emplace_back(1);
	vi.emplace_back(1);

	for(auto& v : vi)
		cout << v << "\t" ;
	cout << endl;

	vector<int> vii{4,3,5,1};
	for(auto& v : vii)
		cout << v << "\t" ;
	cout << endl;

	auto p = vii.begin() + 2;
	vii.push_back(6);
	for(auto& v : vii)
		cout << v << "\t" ;
	cout << endl;

	p = vii.begin() + 2;
	auto p2 = vii.begin() + 4;
	vii.erase(vii.begin()+3);


	for(auto& v : vii)
		cout << v << "\t" ;
	cout << endl;

	return -1;
}
