#include "../hw_defines.h"

void gemm(TYPE_PTR a, TYPE_PTR b, TYPE_PTR c, TYPE n, TYPE m, TYPE p) {

    // m0 is a n*m 2d matrix.
    // input is a m*p 2d matrix
    // c[][] = a[][] * b[][]
    // Parameterize the unrolling of the outer loops
    // Unroll the inner loops to a fixed with 128. 
}
