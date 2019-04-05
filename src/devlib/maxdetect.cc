#include "maxdetect.h"
#include <maxdetect.h>

namespace nodewpi {
    NAN_METHOD(maxDetectRead) {
            SET_ARGUMENT_NAME(0, pin);

            CHECK_ARGUMENTS_LENGTH_EQUAL(1);

            CHECK_ARGUMENT_TYPE_INT32(0);

            int pin = GET_ARGUMENT_AS_INT32(0);

            unsigned char buffer[4];
            int res =::maxDetectRead(pin, buffer);

#if NODE_VERSION_AT_LEAST(0, 11, 0)
            v8::Local<v8::Array> data = ARRAY(4);
#else
            v8::Local<v8::Array> data = v8::Array::New(4);
#endif
            for (int i = 0; i < 4; i++) {
#if NODE_VERSION_AT_LEAST(0, 11, 0)
              data->Set(i, INT32(buffer[i]));
#else
              data->Set(i, Int32::New(buffer[i]));
#endif
            }

#if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Local<v8::Array> ret = ARRAY(2);
    ret->Set(0, INT32(res));
#else
            v8::Local<v8::Array> ret = v8::Array::New(2);
            ret->Set(0, Int32::New(res));
#endif
            ret->Set(1, data);

            info.GetReturnValue().Set(res);
    }

    NAN_METHOD(readRHT03) {
            SET_ARGUMENT_NAME(0, pin);

            CHECK_ARGUMENTS_LENGTH_EQUAL(1);

            CHECK_ARGUMENT_TYPE_INT32(0);

            int pin = GET_ARGUMENT_AS_INT32(0);

            int temp, rh;
            int res =::readRHT03(pin, &temp, &rh);

#if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Local<v8::Array> ret = ARRAY(3);
    ret->Set(0, INT32(res));
    ret->Set(1, INT32(temp));
    ret->Set(2, INT32(rh));
#else
            v8::Local<v8::Array> ret = v8::Array::New(3);
            ret->Set(0, v8::Int32::New(res));
            ret->Set(1, v8::Int32::New(temp));
            ret->Set(2, v8::Int32::New(rh));
#endif

            info.GetReturnValue().Set(res);
    }

    NAN_MODULE_INIT(init_maxdetect) {
            NAN_EXPORT(target, maxDetectRead);
            NAN_EXPORT(target, readRHT03);
    }
}