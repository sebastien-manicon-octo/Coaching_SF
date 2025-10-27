#include "FooBarQix.h"

#include <map>

string divideFooBarQix(int input);
string containFooBarQix(int input);

string convertFooBarQix(int input) {
    string output;
    output.append(divideFooBarQix(input));
    output.append(containFooBarQix(input));

    return !output.empty()
               ? output
               : to_string(input);
}

map<int, string> fooBarQixMap{
        {7, "Qix"},
        {5, "Bar"},
        {3, "Foo"}
};

string divideFooBarQix(int input) {
    string output;
    for (const auto &[key, value]: fooBarQixMap) {
        if (input % key == 0) {
            output.append(value);
        }
    }
    return output;
}

string containFooBarQix(int input) {
    string output;
    for (const char c: to_string(input)) {
        for (const auto &[key, value]: fooBarQixMap) {
            if (c == to_string(key)[0]) {
                output.append(value);
            }
        }
    }
    return output;
}
