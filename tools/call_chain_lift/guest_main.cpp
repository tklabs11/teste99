#include "guest_harness.hpp"

int main() {
    return run_guest_harness(true) ? 0 : 1;
}
