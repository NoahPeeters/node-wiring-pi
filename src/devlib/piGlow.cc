#include "piGlow.h"
#include <piGlow.h>

namespace nodewpi {
  NAN_METHOD(piGlow1) {
      SET_ARGUMENT_NAME(0, leg);
      SET_ARGUMENT_NAME(1, ring);
      SET_ARGUMENT_NAME(2, intensity);

      CHECK_ARGUMENTS_LENGTH_EQUAL(3);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);
      CHECK_ARGUMENT_TYPE_INT32(2);

      int leg = GET_ARGUMENT_AS_INT32(0);
      int ring = GET_ARGUMENT_AS_INT32(1);
      int intensity = GET_ARGUMENT_AS_INT32(2);

      ::piGlow1(leg, ring, intensity);
  }

  NAN_METHOD(piGlowLeg) {
      SET_ARGUMENT_NAME(0, leg);
      SET_ARGUMENT_NAME(1, intensity);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int leg = GET_ARGUMENT_AS_INT32(0);
      int intensity = GET_ARGUMENT_AS_INT32(1);

      ::piGlowLeg(leg, intensity);
  }

  NAN_METHOD(piGlowRing) {
      SET_ARGUMENT_NAME(0, ring);
      SET_ARGUMENT_NAME(1, intensity);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int ring = GET_ARGUMENT_AS_INT32(0);
      int intensity = GET_ARGUMENT_AS_INT32(1);

      ::piGlowRing(ring, intensity);
  }

  NAN_METHOD(piGlowSetup) {
      SET_ARGUMENT_NAME(0, clear);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int clear = GET_ARGUMENT_AS_INT32(0);

      ::piGlowSetup(clear);
  }

  NAN_MODULE_INIT(init_piGlow) {
      NAN_EXPORT(target, piGlow1);
      NAN_EXPORT(target, piGlowLeg);
      NAN_EXPORT(target, piGlowRing);
      NAN_EXPORT(target, piGlowSetup);

      EXPORT_CONSTANT_INT(PIGLOW_RED);
      EXPORT_CONSTANT_INT(PIGLOW_YELLOW);
      EXPORT_CONSTANT_INT(PIGLOW_ORANGE);
      EXPORT_CONSTANT_INT(PIGLOW_GREEN);
      EXPORT_CONSTANT_INT(PIGLOW_BLUE);
      EXPORT_CONSTANT_INT(PIGLOW_WHITE);
  }
}