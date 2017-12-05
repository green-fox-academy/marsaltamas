#include <iostream>
#include <string>
#include <vector>

#include "util.h"

using namespace std;

int main() {
	vector<string> test_data;

	test_data.push_back("2014.2.1 2:22:34 31");
	test_data.push_back("2014.02.1 2:22:34 31");
	test_data.push_back("2014.2.1 2:2:34 31");
	test_data.push_back("2014.20.13 22:22:34 31");
	test_data.push_back("kitten");
	test_data.push_back("2014.2.1 :22:34 31");
	test_data.push_back("2014.2:22:34 31");
	test_data.push_back("something quite random stuff");

	for (int i = 0; i < test_data.size(); i++) {
		try {
			string line = test_data.at(i);
			cout << "parsing: " << line << endl;
			util::temperature_record rec = util::parseLine(test_data.at(i));
			cout << "\tSUCCESS: temperature_record("
				<< "temperature: " << rec.temperature << ", "
				<< "timestamp: " << rec.timestamp << ")" << endl;
		}
		catch (util::ParserException *exc) {
			cout << "\tERROR: " << exc->what() << endl;
		}
	}

}
