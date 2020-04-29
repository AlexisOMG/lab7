#include "declaration.h"

using namespace std;

void test(Egypt a) {
    cout << "\n\nTesting of passing by value\n";
    cout << "Values from function:\n";
    cout << "Recieved value: " << a.getRational() << " = ";
    cout << a;
    a = Egypt(Fraction(3, 7), 3);
    cout << "\nChanged value: " << a.getRational() << " = ";
    cout << a;
}

int main() {
    long long a, b, maxFrac;
    a = 7;
    b = 15;
    maxFrac = 2;

    //Test 1
    Egypt ans = Egypt(Fraction(a, b), maxFrac);
    cout << "Test 1\nMax number of fractions: " << maxFrac << "\n";
    cout << a << "/" << b << " = ";
    cout << ans;

    //Test 2
    maxFrac = 3;
    cout << "\n\nTest 2\nMax number of fractions: " << maxFrac << "\n";
    ans = Egypt(Fraction(a, b), maxFrac);
    cout << ans.getRational() << " = ";
    cout << ans;
    cout << "\nGetting the second fraction: ans[1] = ";
    cout << ans[1];

    //Test 3
    test(ans);
    cout << "\nValue from main:\n";
    cout << ans.getRational() << " = ";
    cout << ans;

    //Test 4
    cout << "\n\nSome interesting values:\n";
    ans = Egypt(Fraction(1, 1), 2);
    cout << ans.getRational() << " = " << ans;
    ans = Egypt(Fraction(0, 1), 4);
    cout << "\n" << ans.getRational() << " = " << ans << "\n";
    return 0;
}
