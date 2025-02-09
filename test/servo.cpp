#define DOCTEST_CONFIG_IMPLEMENT

#include <doctest.h>

int main(int argc, char** argv) {
    doctest::Context context;
    context.setOption("success", true);     // Report successful tests
    context.setOption("no-exitcode", true);

    context.applyCommandLine(argc, argv);
    return context.run();
}
