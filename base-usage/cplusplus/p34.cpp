#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void use()
{
	vector<int> vi { 1, 3, 5, 7, 9};

	cout << "vector<int> vi { 1, 3, 5, 7, 9} capacity: " << vi.capacity() << endl;
	cout << "vector<int> vi { 1, 3, 5, 7, 9} size: " << vi.size() << endl;

	vector<string> vs(7);
	
	cout << "vector<string> vs(7) capacity:  " << vs.capacity() << endl;
	cout << "vector<string> vs(7) size: " << vs.size() << endl;

	vector<int> vi2;

	cout << "vector<int> vi2 capacity: " << vi2.capacity() << endl;
	cout << "vector<int> vi2 size: " << vi2.size() << endl;
	
	vi2 = { 2, 4, 6, 8};

	cout << "vi2 = { 2, 4, 6, 8} capacity: " << vi2.capacity() << endl;
	cout << "vi2 = { 2, 4, 6, 8} size: " << vi2.size() << endl;

	vi2.assign(&vi[1], &vi[4]);
	for(auto& v : vi2)
		cout << v << " ";
	cout << endl;

	cout << "vi2.assign(&vi[1], &vi[4]) capacity: " << vi2.capacity() << endl;
	cout << "vi2.assign(&vi[1], &vi[4]) size: " << vi2.size() << endl;

	vi2.shrink_to_fit();
	cout << "vi2.shrink_to_fit() capacity: " << vi2.capacity() << endl;
	cout << "vi2.shrink_to_fit() size: " << vi2.size() << endl;

	vector<string> vs2;
	cout << "vector<string> vs2 capacity: " << vs2.capacity() << endl;
	cout << "vector<string> vs2 size: " << vs2.size() << endl;

	vs2 = {"The Eagle", "The Bird and Baby"};
	for(auto& v : vs2)
		cout << v << " ";
	cout << endl;

	cout << "vs2 = {\"The Eagle\", \"The Bird and Baby\"} capacity: " << vs2.capacity() << endl;
	cout << "vs2 = {\"The Eagle\", \"The Bird and Baby\"} size: " << vs2.size() << endl;

	vi.clear();
	cout << "vi.clear() capacity: " << vi.capacity() << endl;
	cout << "vi.clear() size: " << vi.size() << endl;

	vi2.clear();
	cout << "vi2.clear() capacity: " << vi2.capacity() << endl;
	cout << "vi2.clear() size: " << vi2.size() << endl;

	vs.clear();
	cout << "vs.clear() capacity: " << vs.capacity() << endl;
	cout << "vs.clear() size: " << vs.size() << endl;

	vs2.clear();
	cout << "vs2.clear() capacity: " << vs2.capacity() << endl;
	cout << "vs2.clear() size: " << vs2.size() << endl;

}

void use2()
{
	int last_capacity = 1;
	vector<int> vi;
	for(int i=0; i<1024*1024; i++){
		vi.push_back(i);
		if(last_capacity != vi.capacity()){
			cout << "vi.push_back(" << i << ") capacity: " << vi.capacity() << endl;
			cout << "vi.push_back(" << i << ") size: " << vi.size() << endl;
			last_capacity = vi.capacity();

//			vi.shrink_to_fit();
//			cout << "vi.shrink_to_fit() capacity: " << vi.capacity() << endl;
//			cout << "vi.shrink_to_fit() size: " << vi.size() << endl;
		}
	}
}

int main()
{
	use();
	use2();
}
