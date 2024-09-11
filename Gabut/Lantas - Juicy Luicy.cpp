#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void printLyrics() {
    struct Line {
        string text;
        chrono::milliseconds charDelay;
    };

    Line lines[] = {
        {"Walau tak ada yang pasti,", chrono::milliseconds(100)},
        {"yang kauberi hanya mimpi", chrono::milliseconds(100)},
        {"Lantas mengapa ku masih menaruh hati?", chrono::milliseconds(100)},
        {"Padahal ku tahu kau t'lah terikat janji", chrono::milliseconds(100)},
        {"Keliru ataukah bukan? Tak tahu", chrono::milliseconds(100)},
        {"Lupakanmu, tapi aku tak mau", chrono::milliseconds(150)},
        {"Pantaskah aku menyimpan rasa cemburu?", chrono::milliseconds(100)},
        {"Padahal bukan aku yang memilikimu", chrono::milliseconds(100)},
        {"Sanggup sampai kapankah? Ku tak tahu", chrono::milliseconds(100)},
        {"Akankah akal sehat menyadarkanku?", chrono::milliseconds(100)},
    };

    chrono::milliseconds delays[] = {
        chrono::milliseconds(1000), // after "Walau tak ada yang pasti,"
        chrono::milliseconds(1000), // after "yang kauberi hanya mimpi"
        chrono::milliseconds(1500), // after "Lantas mengapa ku masih menaruh hati?"
        chrono::milliseconds(1000), // after "Padahal ku tahu kau t'lah terikat janji"
        chrono::milliseconds(1500), // after "Keliru ataukah bukan? Tak tahu"
        chrono::milliseconds(1500), // after "Lupakanmu, tapi aku tak mau"
        chrono::milliseconds(1500), // after "Pantaskah aku menyimpan rasa cemburu?"
        chrono::milliseconds(2000), // after "Padahal bukan aku yang memilikimu"
        chrono::milliseconds(1500), // after "Sanggup sampai kapankah? Ku tak tahu"
        chrono::milliseconds(3000), // after "Akankah akal sehat menyadarkanku?"
    };

    for (size_t i = 0; i < sizeof(lines) / sizeof(lines[0]); ++i) {
        for (char c : lines[i].text) {
            cout << c << flush;
            this_thread::sleep_for(lines[i].charDelay);
        }
        this_thread::sleep_for(delays[i]);
        cout << endl;
    }
}

int main() {
    printLyrics();
    return 0;
}
