#ifndef _WPI_PI_GLOW_H_
#define _WPI_PI_GLOW_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(piGlow1);
  NAN_METHOD(piGlowLeg);
  NAN_METHOD(piGlowRing);
  NAN_METHOD(piGlowSetup);

  NAN_MODULE_INIT(init_piGlow);
}

#endif