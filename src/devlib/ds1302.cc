#include "ds1302.h"
#include <ds1302.h>

// Func: unsigned int ds1302rtcRead (const int reg)
// Description: Reads the data to/from the RTC register
namespace nodewpi {
  NAN_METHOD(ds1302rtcRead) {
      SET_ARGUMENT_NAME(0, reg);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int reg = GET_ARGUMENT_AS_INT32(0);

      unsigned int res =::ds1302rtcRead(reg);

      info.GetReturnValue().Set(res);
  }

// Func: void ds1302rtcWrite (int reg, unsigned int data)
// Description: Writes the data to/from the RTC register

  NAN_METHOD(ds1302rtcWrite) {
      SET_ARGUMENT_NAME(0, reg);
      SET_ARGUMENT_NAME(1, data);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int reg = GET_ARGUMENT_AS_INT32(0);
      unsigned int data = GET_ARGUMENT_AS_UINT32(1);

      ::ds1302rtcWrite(reg, data);
  }

  NAN_METHOD(ds1302ramRead) {
      SET_ARGUMENT_NAME(0, address);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_INT32(0);

      int address = GET_ARGUMENT_AS_INT32(0);

      unsigned int res =::ds1302ramRead(address);

      info.GetReturnValue().Set(res);
  }

  NAN_METHOD(ds1302ramWrite) {
      SET_ARGUMENT_NAME(0, address);
      SET_ARGUMENT_NAME(1, data);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_UINT32(1);

      int address = GET_ARGUMENT_AS_INT32(0);
      unsigned int data = GET_ARGUMENT_AS_UINT32(1);

      ::ds1302ramWrite(address, data);
  }

  NAN_METHOD(ds1302clockRead) {
      CHECK_ARGUMENTS_LENGTH_EQUAL(0);

      int clockData[8];
      ::ds1302clockRead(clockData);

#if NODE_VERSION_AT_LEAST(0, 11, 0)
      v8::Local<v8::Array> res = ARRAY(8);
#else
      v8::Local<v8::Array> res = v8::Array::New(8);
#endif
      for (int i = 0; i < 8; i++) {
#if NODE_VERSION_AT_LEAST(0, 11, 0)
        res->Set(i, INT32(clockData[i]));
#else
        res->Set(i, v8::Int32::New(clockData[i]));
#endif
      }

      info.GetReturnValue().Set(res);
  }

  NAN_METHOD(ds1302clockWrite) {
      SET_ARGUMENT_NAME(0, clockData);

      CHECK_ARGUMENTS_LENGTH_EQUAL(1);

      CHECK_ARGUMENT_TYPE_ARRAY(0);
      CHECK_ARGUMENT_ARRAY_LENGTH(0, 8);

      v8::Local<v8::Array> clockData = v8::Local<v8::Array>::Cast(info[0]);

      int ar[8];
      for (int i = 0; i < 8; i++) {
        ar[i] = clockData->Get(i)->Int32Value();
      }

      ::ds1302clockWrite(ar);
  }

  NAN_METHOD(ds1302trickleCharge) {
      SET_ARGUMENT_NAME(0, diodes);
      SET_ARGUMENT_NAME(1, resistors);

      CHECK_ARGUMENTS_LENGTH_EQUAL(2);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);

      int diodes = GET_ARGUMENT_AS_INT32(0);
      int resistors = GET_ARGUMENT_AS_INT32(1);

      ::ds1302trickleCharge(diodes, resistors);
  }

  NAN_METHOD(ds1302setup) {
      SET_ARGUMENT_NAME(0, clockPin);
      SET_ARGUMENT_NAME(1, dataPin);
      SET_ARGUMENT_NAME(2, csPin);

      CHECK_ARGUMENTS_LENGTH_EQUAL(3);

      CHECK_ARGUMENT_TYPE_INT32(0);
      CHECK_ARGUMENT_TYPE_INT32(1);
      CHECK_ARGUMENT_TYPE_INT32(2);

      int clockPin = GET_ARGUMENT_AS_INT32(0);
      int dataPin = GET_ARGUMENT_AS_INT32(1);
      int csPin = GET_ARGUMENT_AS_INT32(2);

      ::ds1302setup(clockPin, dataPin, csPin);
  }

  NAN_MODULE_INIT(init_ds1302) {
      NAN_EXPORT(target, ds1302rtcRead);
      NAN_EXPORT(target, ds1302rtcWrite);
      NAN_EXPORT(target, ds1302ramRead);
      NAN_EXPORT(target, ds1302ramWrite);
      NAN_EXPORT(target, ds1302clockRead);
      NAN_EXPORT(target, ds1302clockWrite);
      NAN_EXPORT(target, ds1302trickleCharge);
      NAN_EXPORT(target, ds1302setup);
  }
}