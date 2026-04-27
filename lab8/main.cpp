#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

struct CompareMap {
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) const {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
};

int main() {

	ifstream Text_file("file.txt");
	string phrase;
	getline(Text_file, phrase);
	Text_file.close();

	map<string, int> word_count;
	std::string separators = " ,?!.";
	vector<string> words;

    size_t start = phrase.find_first_not_of(separators);
    while (start != string::npos) {
        size_t end = phrase.find_first_of(separators, start);
        string word = phrase.substr(start, end - start);

        for (int j = 0; j < word.length(); j++) {
            word[j] = tolower(word[j]);
        }

        word_count[word]++;
        start = phrase.find_first_not_of(separators, end);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareMap> q;

    for (auto elem : word_count) {
        q.push(elem);
    }

    while (!q.empty()) {
        cout << q.top().first << " => " << q.top().second << endl;
        q.pop();
    }


	return 0;
}





