#include <iostream>

#include <string>
#include <fstream>

using namespace std;

class Textfile {
	public:

	Textfile(string name) {
		setFilename(name);
	}

	void setFilename(string name) {
		filename = name;
	}

	void readFileContents() {
		ifstream olaf(filename);
		string str;
		int count = 0;
		while(getline(olaf, str)) {
			if(str.empty()) {
				continue;
			}
			if(str[0] == '#') {
				continue;
			}
			count++;
		}
		olaf.close();
		numberOfLines = count;
		lines = new string[numberOfLines];

		// open the file again
		olaf.open(filename);
		int i = 0;
		while(getline(olaf, str)) {
			if(str.empty()) {
				continue;
			}
			if(str[0] == '#') {
				continue;
			}
			lines[ i ] = string(str);
			i++;
		}
	}

	string lineAt(int i) {
		return lines[ i ];
	}

	int getNumberOfLines() {
		return numberOfLines;
	}

	~Textfile() {
		if(NULL != lines) {
			delete[] lines;
		}
	}

	private:
	string *lines = NULL;
	string filename;
	int numberOfLines = 0;
};

int main( int argc, char** argv )
{
	Textfile a( argv[1] );
	a.readFileContents();

	for( int i = 0; i < a.getNumberOfLines(); i++ ) {
		cout << i << "\t" << a.lineAt(i) << endl;
	}
}

