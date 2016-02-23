#include <vector>
#include <string>
using namespace std;
void insertion(vector<string>& s){ //http://cforbeginners.com/insertionsort.html
	int length = s.size();
	int j;
	string temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		while (j > 0 && (s[j].length() < s[j-1].length() || (s[j].length() == s[j-1].length() && s[j].compare(s[j-1])) < 0)) {
			temp = s[j];
			s[j] = s[j-1];
			s[j-1] = temp;
			j--;
		}
	}
}