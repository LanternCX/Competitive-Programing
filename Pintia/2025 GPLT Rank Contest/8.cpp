#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		int flg = 0;
		string tag = "ong";
		vector<string> arr;
		while (1) {
			cin >> s;
			arr.push_back(s);
            if (s[s.length() - 1] == ',') {
                if (s.length() >= 4 && s.substr(s.length() - 4, 3) == "ong") {
                    flg++;
                }
            }

            if (s[s.length() - 1] == '.') {
                if (s.length() >= 4 && s.substr(s.length() - 4, 3) == "ong") {
                    flg++;
                }
                break;
            }
		}
		
		if (flg == 2) {
			for (int i = 0; i < arr.size() - 3; i++) {
				cout << arr[i] << ' ';
			}
			cout << "qiao ben zhong.\n";
		} else {
			cout << "Skipped\n";
		}
	}
	return 0;
}
