// Bayer-Moore Algorithm 
/*
	Right-to-left comparison:
 			Compare pattern with text from rightmost character to left
	Two heuristics: 
 			Use bad character and good suffix rules to skip unnecessary comparisons
	Efficient skipping: 
 			Jump multiple positions when mismatch occurs



  1. Bad Character Heuristic : 
  			mismatch occurs - text character - caused mismatch
	 		shift pattern to align charcter - last occurrence in pattern
	
  2. Good Suffix Heuristic : 
  			suffix matches - mismatch occures
	 		shift pattern - align matched suffix - previous occirence 
*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define No_of_Chars 256

using namespace std;

// preprocessing Bad character Heurisitc
void BadCharHeuristic(const string& pattern , vector<int> &badchar) {
  int m = pattern.size();

  // Initialize all occurrence as -1
  fill(badchar.begin() , badchar.end() , -1);
  
  //fill the actual value of last occurence of each character
  for (int i = 0; i < n; i++) {
    badchar[(int)pattern[i]] = i;
  }
}

// Preprocessing for seed Suffix Heuristic (simplified version)
void goodSuffixHeuristic(const string& pattern, vector<int> &shift) {
  int m = pattern.size();
  vector<int> border(m + 1, 0);

  //Procompute borders
  int i = m , j = m + 1;
  border[i] = j;

  while (i > 0) {
    while (j <= m && pattern[i - 1] != pattern[j -1]) {
      if (shift[j] == 0) {
          shift[j] = j - 1;
      }
      j  = border[j];
    }
    i--;
    j--;
    border[i] = j;
  }
  // second case
  j = border[0];
  for (i = 0; i<= m; i++) {
      if(shift[i] == 0) {
        shift[i] = j;
      }
      if (i == j) {
        j = border[j];
      }
  }
}
    void boyerMooreSearch(const string& text , const string& pattern) {
        int n = text.size();
        int m = pattern.size();

        vector<int> badchar(No_of_Chars , -1);
        vector<int> goodSuffix(m + 1 , 0);

        //Preepocessing 
        badCharHeuristic(pattern, badchar);
        goodSuffixHeuristic(pattern , goodSuffix);

        int s = 0;

        cout<< " step-by-step execution:\n";
        cout << " Text windoe: " << text.substr(s , m) << endl;

        // keep reducing index j of pattern while characters match
        while (j >= 0 && pattern[j] == text[s + j])  j--;

        if (j < 0) {
            cout << "✓ Pattern found at index " << s << endl << endl;
            
            // Shift the pattern using good suffix heuristic
            s += goodSuffix[0];
        } else {
            cout << "✗ Mismatch at position " << s + j << " (text char: " 
                 << text[s + j] << ", pattern char: " << pattern[j] << ")" << endl;
            
            // Calculate shift using both heuristics
            int badCharShift = max(1, j - badchar[text[s + j]]);
            int goodSuffixShift = goodSuffix[j + 1];
            
            // Use the maximum shift from both heuristics
            s += max(badCharShift, goodSuffixShift);
            
            cout << "Bad character shift: " << badCharShift << endl;
            cout << "Good suffix shift: " << goodSuffixShift << endl;
            cout << "Actual shift: " << max(badCharShift, goodSuffixShift) << endl << endl;
        }
    }
}
