#if !defined __GNUC__
#pragma warning( disable: 4571 4820 4514 4987 4710 4309 4986 4548)
#include <crtdbg.h>
#endif

#include <iostream>
#include <iomanip>

using std::cout;
using std::cerr;
using std::endl;

using std::hex;
using std::setw;
using std::setfill;
using std::dec;

#include "SafeInt3.hpp"

#if !defined(COUNTOF)
# if defined(_countof)
#  define COUNTOF(x) _countof(x)
# else
#  define COUNTOF(x) (sizeof(x)/sizeof((x)[0]))
# endif
#endif

#define HEX(x) hex << setw(x) << setfill('0')

namespace mult_verify { void MultVerify(); }
namespace div_verify { void DivVerify(); }
namespace sub_verify { void SubVerify(); }
namespace add_verify { void AddVerify(); }
namespace mod_verify { void ModVerify(); }
namespace incdec_verify { void IncDecVerify(); }

