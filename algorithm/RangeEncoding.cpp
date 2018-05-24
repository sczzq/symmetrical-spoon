#include <iostream>
#include <string>
//#include <cinttypes>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int revisedAlgorithm()
{
	string a = "NMLNNNKKNML";
	std::map<char, double> fa; //{0.1, 0.21, 0.27, 0.42};
	std::map<char, double> Fa; // {0,   0.1,  0.31, 0.58};
	fa['K'] = 0.1; fa['L'] = 0.21; fa['M'] = 0.27; fa['N'] = 0.42;
	Fa['K'] = 0;   Fa['L'] = 0.1;  Fa['M'] = 0.31; Fa['N'] = 0.58;
	uint64_t w = 3, b = 10;

	vector<double> R(a.length()+1), B(a.length()+1), S(a.length()+1), T(a.length()+1), k(a.length()+1);
	double s = pow(b, w);

	int i = 0;
	R[0] = s; S[0] = 0; T[0] = 1, B[0] = 0;
	for(i=1; i<=a.length(); i++){
		k[i]  = w - ceil(log10(T[i-1] - B[i-1]));
		R[i] = (T[i-1] - B[i-1]) * pow(b, k[i]);
		B[i] = B[i-1] * pow(b, k[i]) + floor(R[i] * Fa[a[i-1]]);
		T[i] = B[i-1] * pow(b, k[i]) + floor(R[i] * (fa[a[i-1]] + Fa[a[i-1]]));
		S[i] = S[i-1] + k[i];
		printf("k[%d]=%5.lf, R[%d]=%5.lf, B[%d]=%5.lf, T[%d]=%5.lf, S[%d]=%5.lf\n", i, k[i], i, R[i], i, B[i], i, T[i], i, S[i]);
	}
	
	printf("Remaining Width\t Next Letter\t Range of Next Letter\t Message so far\t Range of message so far\t Remaining width\t\n");
	for(i=1; i<=a.length(); i++){
		printf("%12.lf\t %c\t [%12.lf %12.lf)\t ", R[i], a[i-1], floor(R[i-1] * Fa[a[i-1]]), floor(R[i-1] * (Fa[a[i-1]] + fa[a[i-1]])));
		int j = 0;
		for(j=0; j<i; j++)
			printf("%c", a[j]);
		printf("\t [%12.lf %12.lf)\t, %12.lf\n", B[i], T[i], T[i]-B[i]);
	}

}

int basicAlgorithm()
{
	string a = "NMLNNNKKNMLNMKLLLNNMMM";
	std::map<char, double> fa; //{0.1, 0.21, 0.27, 0.42};
	std::map<char, double> Fa; // {0,   0.1,  0.31, 0.58};
	fa['K'] = 0.1; fa['L'] = 0.21; fa['M'] = 0.27; fa['N'] = 0.42;
	Fa['K'] = 0;   Fa['L'] = 0.1;  Fa['M'] = 0.31; Fa['N'] = 0.58;

	vector<double> Rf(a.length()+1), RF(a.length()+1), R(a.length()+1), B(a.length()+1);
	double s = pow(10, 11);
	Rf[0] = s;

	printf("%lld\n", s);

	int i = 0;
	for(i=1; i<=a.length(); i++){
		Rf[i] =  Rf[i-1] * fa[a[i-1]] ;
		RF[i] =  Rf[i-1] * Fa[a[i-1]] ;
	}

	R[0] = Rf[0]; B[0] = 0;
	for(i=1; i<=a.length(); i++){
		R[i] = floor(Rf[i]);
		B[i] = floor(B[i-1] + RF[i]);
	}

	printf("Remaining Width\t Next Letter\t Range of Next Letter\t Message so far\t Range of message so far\t\n");
	for(i=1; i<=a.length(); i++){
		printf("%12.lf\t %c\t [%12.lf %12.lf)\t ", R[i-1], a[i-1], RF[i], RF[i]+Rf[i]);
		int j = 0;
		for(j=0; j<i; j++)
			printf("%c", a[j]);
		printf("\t [%12.lf %12.lf)\t\n", B[i], B[i]+R[i]);
	}

	return 0;
}

int main()
{
//	basicAlgorithm();
	revisedAlgorithm();
	return 0;
}
