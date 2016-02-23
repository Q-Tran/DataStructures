#include <vector>
#include <String>
void selection(std::vector<std::string> &s{
	int smallestI;
	int str2L;
	int str1L;
	std::string tmp;
	int vLength = s.size();
	for(int i = 0; i < vLength; i++){
		str1L = s[i].length();
		smallestI = str1L;
		for(int a = i + 1; a < vLength; a++){
			str2L = s[a].length();
			if (str2L < str1L){
				smallestI = a;
			}
			else if(str1L == str2L){
				if(s[i].compare(s[a]) < 0){
					smallestI = a;
				}
			}
		}
		if(smallestI != i){
			tmp = s[i];
			s[i] = s[smallestI];
			s[smallestI] = tmp;
		}
	}
}