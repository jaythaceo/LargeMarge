#ifndef HASHMAP_BITMAP
#define HASHMAP_BITMAP

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#include <inttypes.h>
#include <string.h>

#include <string>
#include <iostream>

namespace hashmap {

  class BitmapHashMap: public HashMap
  {
    BitmapHashMap(uni64_t size,
                  uni64_t size_probing) {
      buckets = NULL;
      num_buckets = size;
      size_neighborhood_ = 32;
      size_probing = size_probing;
    }
  };
}



#endif // __STDC_FORMAT_MACROS
