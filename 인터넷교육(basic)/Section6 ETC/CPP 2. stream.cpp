
// =============iostream=============
#include<iostream>
#include<string>
using namespace std;
cin.fail() // 입력이 실패했는데 확인가능함
cin.clear() // cin의 상태를 나타내는 비트를 reset
cin.ignore() // 입력 버퍼를 비운다. 한자리 비우기
cin.ignore(256, '\n');

// cin 문자열 입출력
// "aaa bbb"  단어 입력

string s;
cin >> s; // 단어 입력
getline(cin,s); // 문자열 입력

// =============file stream=============
#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    cout << "hello";
    ofstream f("a.txt");
    f << "hello"; //a.txt에 출력

    string s;
    ifstream fin("file2.cpp");
    fin >> s; // 이 파일의 첫번째 단어
    getline(fin,s);// 한줄 입력

    vector<string> v;

    while(getline(fin,s))
        v.push_back(s);

    reverse(v.begin(), v.end());
    reverse(v[0].begin(), v[0].end()); // 첫번째 줄

    
    for(auto& n : v)
        std::cout << n << endl;
}