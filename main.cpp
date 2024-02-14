#include <cstring>
#include <string>
#include <iostream>
#include <random>

using namespace std;
string generateRandomString(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, characters.size() - 1);

    string randomString;
    randomString.reserve(length);

    for (int i = 0; i < length; ++i) {
        randomString += characters[distribution(generator)];
    }

    return randomString;
}
bool areArraysEqual(const char array1[], const char array2[], int size) {
    for (int i = 0; i < size; ++i) {
        if (array1[i] != array2[i]) {
            return false;  // Found a mismatch at index i
        }
    }
    return true;  // All elements are equal
}

int main(){
    cout<<"Enter the string"<<endl;
    string s;
    getline(cin, s);
    cout<<endl;
    const int length = s.length();
    char* char_array = new char[0];
    string random = generateRandomString(length);
    char* random_array = new char[0];
    strcpy(char_array, s.c_str());
    strcpy(random_array, random.c_str());
    while(!areArraysEqual(char_array,random_array,length)){
        for(int i = 0; i<length;i++){
            if(random_array[i]<char_array[i]){
                random_array[i]++;
            }
            else if(random_array[i]>char_array[i]){
                random_array[i]--;
            }
        }
        for (int i = 0; i < length; i++)
        {
            std::cout << random_array[i];
        }
        cout<<endl;
    }

    delete[] char_array;
    delete[] random_array;
    return 0;
}