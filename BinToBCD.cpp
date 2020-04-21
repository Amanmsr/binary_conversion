#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<map>

using namespace std;

int main() {
	int choice;
	map<int, string> m;
	vector<int> digit(3);
	m.insert(make_pair(0, "0000"));
	m.insert(make_pair(1, "0001"));
	m.insert(make_pair(2, "0010"));
	m.insert(make_pair(3, "0011"));
	m.insert(make_pair(4, "0100"));
	m.insert(make_pair(5, "0101"));
	m.insert(make_pair(6, "0110"));
	m.insert(make_pair(7, "0111"));
	m.insert(make_pair(8, "1000"));
	m.insert(make_pair(9, "1001"));
	do {
		cout << "1 - Binary to BCD." << endl << "2 - BCD to Binary." << endl << "-1 - Exit." << endl << "Enter your choice: " << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter the binary number:" << endl;
			string num, result = "";
			cin.ignore();
			getline(cin, num);
			bitset<8> b(num);
			int d = b.to_ulong();
			digit[0] = d % 10;
			digit[1] = (d / 10) % 10;
			digit[2] = d / 100;
			for (int i = 2; i >= 0; i--) {
				result += m[digit[i]];
				result += " ";
			}
			cout << "BCD representation is: " << result << endl;
		}
		else if (choice == 2) {
			string bcd;
			digit.clear();
			cout << "Enter the BCD number: " << endl;
			cin.ignore();
			getline(cin, bcd);
			int p = 12 - bcd.size();
			for (int i = 0; i < p; i++)
				bcd = "0" + bcd;
			string place;
			for (int i = 0; i < 12; i = i + 4) {
				place = "";
				for (int j = i; j < (i + 4); j++) {
					place += bcd[j];
				}
				for (int k = 0; k < 10; k++) {
					if (m[k] == place) {
						digit.push_back(k);
						break;
					}
				}
			}
			int ans = digit[2] + 10 * digit[1] + 100 * digit[0];
			bitset<8> b1(ans);
			cout << "The binary representation is: " << b1 << endl;
		}
		else if (choice == -1)
			cout << "Thanks for playing." << endl;
		else
			cout << "Invalid Input, Try again." << endl;
	} while (choice != -1);
	return 0;
}
