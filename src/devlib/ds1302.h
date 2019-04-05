#ifndef _WPI_DS1302_H_
#define _WPI_DS1302_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(ds1302rtcRead);
  NAN_METHOD(ds1302rtcWrite);
  NAN_METHOD(ds1302ramRead);
  NAN_METHOD(ds1302ramWrite);
  NAN_METHOD(ds1302clockRead);
  NAN_METHOD(ds1302clockWrite);
  NAN_METHOD(ds1302trickleCharge);
  NAN_METHOD(ds1302setup);

  NAN_MODULE_INIT(init_ds1302);
}

#endif