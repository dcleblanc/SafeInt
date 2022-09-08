#include "../../safe_math.h"

void call_functions(void);

int main(int argc, char** argv)
{
    argc++;
    argv++;
    call_functions();
    return 0;
}
