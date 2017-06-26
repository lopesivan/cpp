#include <iostream>
#include <memory>
#include <cstdint>
using namespace std;

struct x
{
    int32_t xa;
    unique_ptr<double[]> xb;

    x(int32_t i) :
        xa(i),
        xb(unique_ptr<double[]>(new double[i])) {}
};

int main() {
    x lines[10](5);
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            lines[i].xb[j] = 10.5;
        }
    }
    return 0;
}
