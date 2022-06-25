#include <iostream>
#include <string>
#include<fstream>
#include<vector>

using namespace std;



void karpRabin(string txt, string wzorzec);

int main() {

	int test;
	string txt, wzorzec;
	cin >> test;
	for (int c = 0; c < test; c++) {

		cin >> txt;
		cin.ignore();
		getline(cin, wzorzec);

		ifstream file;
		file.open(txt);
		getline(file, txt);

		karpRabin(txt, wzorzec);

		if(c!=test-1)cout << "\n";
		
	}

		return 0;
	
}
void karpRabin(string txt, string wzorzec) {

	long long hWzorzec=0, h0=0, PP = 256, P = 15488917, pov=1;
	int i, j;
	//hash for pattern and first 
	for (i = 0; i < wzorzec.length(); i++) {
		hWzorzec = (PP * hWzorzec + wzorzec[i]) % P;
		h0 = (PP * h0 + txt[i]) % P;
	}
	i = 0;

	//pow
	for (i = 0; i < wzorzec.length() - 1; i++) {

		pov = (pov * PP) % P;
	}

	bool flag = true, first = true;
	for (int i = 0; i < txt.length() - wzorzec.length(); i++) {
		

		if (hWzorzec == h0) {

			for (j = 0; j < wzorzec.length(); j++) {
				if (txt[j+i] != wzorzec[j])
				{
					flag = false;
					break;
				}
			}
			if (flag && !first) cout << " " << i;
			else {
				cout << i;
				first = false;
			}
		}

		if (i < txt.length() - wzorzec.length())
		{
			h0 = (PP * (h0 - txt[i] * pov) + txt[i + wzorzec.length()]) % P;
			if (h0 < 0) h0 += P;
		}

	}
	
}


