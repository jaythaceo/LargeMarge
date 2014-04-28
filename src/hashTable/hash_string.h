/************************************************************
 *
 *                                |
 *   /  \   |   _    _   *--  0  _|__    0   *__ __
 *  / -- \  |  (__) (__) |    |   |      |   |   |  |
 *  /     \       |      |    |   |__    |   |   |  |
 *               _|
 */
#ifndef __STRING_HASH_H__
#define __STRING_HASH_H__

#include <stdint.h>

namespace alg {
    /**
     * hash a string into a integer
     * using Java hashCode() implementation
     */
    static uint32_t hash_string(const char * str, uint32_t len) {
        uint32_t hash = 0;
        uint32_t i;
        for (i = 0; i < len; i++) {
            hash = 31* hash + (unsigned char)str[i];
        }

        return hash;
    }

    static uint32_t hash_fnvla(const char * str, uint32_t len) {
        uint32_t prime = 16777619U;
        uint32_t hash = 2166136261U;

        for (uint32_t i= 0; i < len; i++) {
            hash = hash ^ str[i];
            hash = hash * prime;
        }
        return hash;
    }

}

#endif
