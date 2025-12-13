#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
class Hex {
public:
    string type;
    int value;
    int places;
    Hex() : value(0), type("hex"), places(0) {}
    Hex(int v, string t, int p) {
        value = v;
        type = t;
        places = p;
    }
};
ostream& operator<<(ostream& os, const Hex& h) {
    auto old_flags = os.flags();
    auto old_fill  = os.fill();

    os << "0x"
       << uppercase
       << hex
       << setw(h.places)
       << setfill('0')
       << h.value;

    os.flags(old_flags);
    os.fill(old_fill);
    return os;
}

int main() {
    map<string, Hex> REG;
    map<int, Hex> MEM;
    for (int i = 0; i < 255; i++){
        MEM[i] = Hex(0, "HEX", 2);
    }
    cout << MEM.at(0) << endl;
    return 0;
}