#include <iostream>
#include <cstring>
using namespace std;

//hashtable

class HashTable 
{
private:
	string* arrData;
	long* arrKey; 
	bool* isTaken;
	long taken;
	long size;
public:
	~HashTable() {
		delete[] arrData;
		delete[] isTaken;
		delete[] arrKey;
		taken = 0;
		size = 0;
	}
	HashTable(long i) {
		
		size = i;
		taken = 1;
		arrData = new string[size];
		arrKey = new long[size];
		isTaken = new bool[size];
		for (int i = 0; i < size; i++) {
			isTaken[i] = 0;
		}
	}

	long calcHash(long key){
	
		return key % size;
	}

	void insertData(long key, string data) {
		
		if (taken <= size) {
			
			long result = calcHash(key);
			while (isTaken[result]&& arrKey[result] != key) {
				
				
				result++;
				if (result > size) result = 0; 
			}
			isTaken[result] = 1;
			arrData[result] = data;
			arrKey[result] = key;
			taken++;
		}
	}

	void removeData(long key) {
		
		long iter = 0;
		long result = calcHash(key);
		while ((isTaken[result] == 0 || arrKey[result]!= key)&&iter<=size) {
			iter++;
			result++;
			if (result > size) result = 0;
		}
		if (iter <= size) {
			isTaken[result] = 0;
			taken--;
			//tasowanie
			shuffle(result);
			
		}
		

	}
	void shuffle(long freeOne) {
		
		long iter = 0, temp = freeOne+1;
		while (isTaken[temp] == 1 && iter <= size+1) {
			iter++;
			temp++;
			if (temp > size) temp = 0;
		}
	
		if (iter <= size) {
			
			temp--;
			
			iter = 0;
			if (temp > freeOne) {
				while (calcHash(arrKey[temp]) > freeOne && temp>=freeOne) {
					temp--;
				}
				if (temp > freeOne) {
					arrKey[freeOne] = arrKey[temp];
					arrData[freeOne] = arrData[temp];
					isTaken[freeOne] = 1;
					isTaken[temp] = 0;
					shuffle(temp);

				}
			}else if (temp < freeOne) {
				while (calcHash(arrKey[temp]) < freeOne && temp <= freeOne) {
					temp++;
				}
				if (temp < freeOne) {
					arrKey[freeOne] = arrKey[temp];
					arrData[freeOne] = arrData[temp];
					isTaken[freeOne] = 1;
					isTaken[temp] = 0;
					shuffle(temp);

				}
			}
		}
	}
	void display() {
		
		for (int i = 0; i <= size; i++) {
			
			if (isTaken[i] == 1) cout << i << " " << arrKey[i] << " " << arrData[i]<<"\n";
		}
	}
	
};

int main()
{
	int x;
	long hm;
	long key;
	string option, data;
	cin >> hm;
	for (int i = 0; i < hm; i++)
	{
		cin >> option>> x;
		HashTable uno(x);
		while (option != "stop") {
			cin >> option;
			
			if (option == "add") {
			
				cin >> key >> data;
				
				uno.insertData(key, data);
			}
			else if (option == "delete") {
				
				cin >> key;
				
				uno.removeData(key);
			}else if(option == "print"){
		
				uno.display();

			}
		}


	}
	return 0;
}