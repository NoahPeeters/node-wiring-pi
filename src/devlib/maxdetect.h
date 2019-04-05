#ifndef _WPI_MAXDETECT_H_
#define _WPI_MAXDETECT_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(maxDetectRead);
  NAN_METHOD(readRHT03);

  NAN_MODULE_INIT(init_maxdetect);
}

#endif