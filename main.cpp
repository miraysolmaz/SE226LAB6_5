#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxsize = 100;

bool is_palindrome(string s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

const int maxnum = 1000000;

int numbers[] = {2, 3, 4, 5, 6, 7, 8};
bool isPrime[maxnum+1];

int sieve_of_eratosthenes(int* numbers, int n) {
    int numPrimes = 0;
    fill_n(isPrime, n, true);
    for (int i = 0; i < n; i++) {
        if (isPrime[numbers[i]]) {
            int number = numbers[i];
            if (number > 1) {
                numPrimes++;
            }
            for (int j = number * 2; j <= maxnum; j += number) {
                isPrime[j] = false;
            }
        }
    }
    return numPrimes;
}
string toLowercase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string removeSpaces(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    return s;
}

string sortString(string s) {
    sort(s.begin(), s.end());
    return s;
}

bool areAnagrams(string s1, string s2) {
    s1 = sortString(removeSpaces(toLowercase(s1)));
    s2 = sortString(removeSpaces(toLowercase(s2)));

    return s1 == s2;
}

    int main() {

//Question1
        int list1[] = {1, 2, 3, 4, 5, 6, 7};
        int list2[] = {4, 5, 6, 7, 8, 9, 10};
        int n1 = sizeof(list1) / sizeof(list1[0]);
        int n2 = sizeof(list2) / sizeof(list2[0]);

        int common[n1 < n2 ? n1 : n2];
        int k = 0;

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (list1[i] == list2[j]) {
                    bool isUnique = true;
                    for (int m = 0; m < k; m++) {
                        if (common[m] == list1[i]) {
                            isUnique = false;
                            break;
                        }
                    }
                    if (isUnique) {
                        common[k] = list1[i];
                        k++;
                    }
                }
            }
        }

        for (int i = 0; i < k; i++) {
            cout << common[i] << " ";
        }
        cout << endl;
//-------------------
//Question2
        string inlist[maxsize] = {"kek", "pop", "love", "ses"};
        string palindromes[maxsize];
        int count = 0;
        for (int i = 0; i < maxsize; i++) {
            if (inlist[i] == "") {
                break;
            }
            if (is_palindrome(inlist[i])) {
                palindromes[count] = inlist[i];
                count++;
            }
        }
        for (int i = 0; i < count; i++) {
            cout << palindromes[i] << " ";
        }
        cout << endl;
//-------------------
//Question3
int n = sizeof(numbers) / sizeof(int);
        int numPrimes = sieve_of_eratosthenes(numbers, n);
        cout << "The number of prime numbers: " << numPrimes << endl;
        for (int i = 2; i <= maxnum; i++) {
            if (isPrime[i]) {
               cout << i ;
            }
        }
//-------------------
//Question4
        string word = "listen";
        string wordList[] = {"enlists", "google", "inlets", "banana"};
        int a = sizeof(wordList) / sizeof(wordList[0]);

        for (int i = 0; i < n; i++) {
            if (areAnagrams(word, wordList[i])) {
                cout << wordList[i] << " ";
            }
        }
    return 0;
}