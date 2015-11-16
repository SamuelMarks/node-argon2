#include <cstring>
#include <malloc.h>

#include "argon2_wrapper.h"
#include "argon2.h"

int argon2_wrapper::hash_string(const char *password,
                                u_short hash_len,
                                u_short salt_len,
                                uint32_t t_cost,     // 1-pass computation
                                uint32_t parallelism // number of threads and lanes
) {
    uint8_t hash1[hash_len];
    uint8_t hash2[hash_len];

    uint8_t salt[salt_len];
    memset(salt, 0x00, salt_len);

    uint8_t *pwd = (uint8_t *) strdup(password);
    uint32_t pwdlen = strlen((char *) pwd);

    uint32_t m_cost = (1 << 16);      // 64 mebibytes memory usage

    // high-level API
    argon2i_hash_raw(t_cost, m_cost, parallelism, pwd, pwdlen, salt, salt_len, hash1, hash_len);

    // low-level API
    uint32_t lanes = parallelism;
    uint32_t threads = parallelism;
    argon2_context context = {
            hash2, hash_len,
            pwd, pwdlen,
            salt, salt_len,
            NULL, 0, /* secret data */
            NULL, 0, /* associated data */
            t_cost, m_cost, lanes, threads,
            NULL, NULL, /* custom memory allocation / deallocation functions */
            ARGON2_DEFAULT_FLAGS /* by default the password is zeroed on exit */
    };
    argon2i(&context);
    free(pwd);

    for(int i = 0; i < hash_len; ++i) printf("%02x", hash1[i]);
    printf("\n");
    if (memcmp(hash1, hash2, hash_len)) {
        for(int i = 0; i < hash_len; ++i)
            printf("%02x", hash2[i]);
        printf("\n");
        printf("fail\n");
    }
    else printf("ok\n");

    return 0;
}