// math.h must be included before any decomp headers to prevent issues that stem from defining `this`.
#include "math.h"

// Define `this` before including decomp headers to work around it being a keyword in C++.
#define this this_
extern "C" {
#include "global.h"
}
// Undo the `this` define.
#undef this

#include "modding.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "string_printf.hpp"

#include <string>
#include <vector>
#include "recompdatawrappers/u32valuehashmap.hpp"

using namespace RecompDataWrapper;

RECOMP_CALLBACK("*", recomp_on_init)
void on_init() {
    recomp_printf("Constructing U32ValueHashmap valueHash...\n");
    U32ValueHashmap valueHash;

    recomp_printf("valueHash.insert(1, 2) returned %d (should be 1)\n", valueHash.insert(1, 2));

    unsigned long out = 0;
    int result = valueHash.get(2, out);
    recomp_printf("valueHash.get(2, out) returned %d (should be 0) and out is %d (should be 0)\n", result, out);

    result = valueHash.get(1, out);
    recomp_printf("valueHash.get(1, out) returned %d (should be 1) and out is %d (should be 2)\n", result, out);

    recomp_printf("valueHash.erase(1) returned %d (should be 1) and return of valueHash.get(1, out) afterward is %d (should be 0)\n", valueHash.erase(1), valueHash.get(1, out));
}
