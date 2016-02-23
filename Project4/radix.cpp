#include <vector>
#include <string>
#include "insertion.h"
using namespace std;
void radix(vector<string> &s){ //first sorts alphabetically and then sorts by length to make it sorted by length and within each length alphabetically.
	//96% must be correct. According to this website using english word frequencies I should be safe assuming 9 letters max in each word. http://norvig.com/mayzner.html
	int length = s.size();
	msd(s, 0, length, 0);
}

void msd(string[] a, int lo, int hi, int d){
    if (hi <= lo+1) return;
    int[] count = new int[256+1];
    for (int i = 0; i < N; i++)
        count[a[i].charAt(d)+1]++;
    for (int k = 1; k < 256; k++)
        count[k] += count[k-1];
    for (int i = 0; i < N; i++)
        temp[count[a[i].charAt(d)]++] = a[i];
    for (int i = 0; i < N; i++)
        a[i] = temp[i];
    for (int i = 0; i < 255; i++)
       msd(a, l+count[i], l+count[i+1], d+1);
}
