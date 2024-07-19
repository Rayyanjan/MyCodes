#include <iostream>
#include <vector>

void process(int x) {
    if (x == 1)
        throw 1; // throw int exception
    else if (x == 2)
        throw "yikes"; // throw const char* exception
}

int main() {
    std::vector<int> nums = {0, 1, 2, 3};

    for (int x : nums) {
        try {
            process(x);
            std::cout << "okay\n";
        } catch (int ex) {
            std::cout << "Caught exception of type int: " << ex << std::endl;
        } catch (const char* ex) {
            std::cout << "Caught exception of type const char*: " << ex << std::endl;
        }
    }

    return 0;
}
  