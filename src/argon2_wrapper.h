//
// Created by samuelm on 16/11/15.
//

#ifndef NODE_ARGON2_ARGON_WRAPPER_CPP_H

#include <sys/types.h>
#include <stdint.h>

namespace argon2_wrapper {
    int hash_string(const char *password,
                    u_short hash_len = 32,
                    u_short salt_len = 16,
                    uint32_t t_cost = 2,     // 1-pass computation
                    uint32_t parallelism = 1 // number of threads and lanes
    );
}

#define NODE_ARGON2_ARGON_WRAPPER_CPP_H

#endif //NODE_ARGON2_ARGON_WRAPPER_CPP_H
