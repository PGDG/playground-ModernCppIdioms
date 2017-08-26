#include "Exercises/Universe.h"

#include <string>
#include <iostream>
#include <sstream>
#include "helpers/helpers.h"

using namespace std;
using namespace modern_cpp::helpers;

void Message(string channel, string msg) {
    stringstream ss(msg);
    string line;
    while (getline(ss, line, '\n')) {
        cout << "TECHIO> message --channel \"" << channel << "\" \"" << line << "\"" << endl;
    }
}

void Success(bool success) {
    cout << "TECHIO> success " << (success ? "true" : "false") << endl;
}

void AssertEquals(int expected, int found, string message) {
    if(expected != found) {
        ostringstream error;
        error << message << " Expected: " << expected << ", Found: " << found  << endl;
        throw logic_error(error.str());
    }
}

int main() {
    try {
        vector<int> galaxy1 {2, 3};
        AssertEquals(5, Universe::CountAllStars(galaxy1), "Running Universe::CountAllStars(2, 3)...");

        vector<int> galaxy2 {9, -3};
        AssertEquals(6, Universe::CountAllStars(galaxy2), "Running Universe::CountAllStars(9, -3)...");
        Success(true);

        if (exists_in_file("accumulate", "src/Exercises/Universe.cpp")) {
            Message("My personal Yoda, you are. 🙏", "* ● ¸ .　¸. :° ☾ ° 　¸. ● ¸ .　　¸.　:. • ");
            Message("My personal Yoda, you are. 🙏", "           　★ °  ☆ ¸. ¸ 　★　 :.　 .   ");
            Message("My personal Yoda, you are. 🙏", "__.-._     ° . .　　　　.　☾ ° 　. *   ¸ .");
            Message("My personal Yoda, you are. 🙏", "'-._\\7'      .　　° ☾  ° 　¸.☆  ● .　　　");
            Message("My personal Yoda, you are. 🙏", " /'.-c    　   * ●  ¸.　　°     ° 　¸.    ");
            Message("My personal Yoda, you are. 🙏", " |  /T      　　°     ° 　¸.     ¸ .　　  ");
            Message("My personal Yoda, you are. 🙏", "_)_/LI");
        } else {
            Message("Kudos 🌟", "Did you know that you can use the accumulate method to sum up a vector? Try it!");
            Message("Kudos 🌟", " ");
            Message("Kudos 🌟", "#include <numeric>");
            Message("Kudos 🌟", " ");
            Message("Kudos 🌟", "vector<int> galaxies {37, 3, 2};");
            Message("Kudos 🌟", "int totalStars = accumulate(galaxies.begin(), galaxies.end(), 0); // 42");
        }

    } catch (const exception& e)  {
        Success(false);
        Message("Oops! 🐞", e.what());
        Message("Hint 💡", "Did you properly accumulate all stars into 'totalStars'? 🤔");
    }

  return 0;
}
