#include "lcd128x64.h"
#include <lcd128x64.h>

namespace nodewpi {
    NAN_METHOD(lcd128x64setOrigin) {
            SET_ARGUMENT_NAME(0, x);
            SET_ARGUMENT_NAME(1, y);

            CHECK_ARGUMENTS_LENGTH_EQUAL(2);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);

            int x = GET_ARGUMENT_AS_INT32(0);
            int y = GET_ARGUMENT_AS_INT32(1);

            ::lcd128x64setOrigin(x, y);
    }

    NAN_METHOD(lcd128x64setOrientation) {
            SET_ARGUMENT_NAME(0, orientation);

            CHECK_ARGUMENTS_LENGTH_EQUAL(1);

            CHECK_ARGUMENT_TYPE_INT32(0);

            int orientation = GET_ARGUMENT_AS_INT32(0);

            ::lcd128x64setOrientation(orientation);
    }

    NAN_METHOD(lcd128x64orientCoordinates) {
            CHECK_ARGUMENTS_LENGTH_EQUAL(0);

            int x, y;
            ::lcd128x64orientCoordinates(&x, &y);

#if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Local<v8::Array> res = ARRAY(2);
    res->Set(0, INT32(x));
    res->Set(1, INT32(y));
#else
            v8::Local<v8::Array> res = v8::Array::New(2);
            res->Set(0, v8::Int32::New(x));
            res->Set(1, v8::Int32::New(y));
#endif

            info.GetReturnValue().Set(res);
    }

    NAN_METHOD(lcd128x64getScreenSize) {
            CHECK_ARGUMENTS_LENGTH_EQUAL(0);

            int x, y;
            ::lcd128x64getScreenSize(&x, &y);

#if NODE_VERSION_AT_LEAST(0, 11, 0)
    v8::Local<v8::Array> res = ARRAY(2);
    res->Set(0, INT32(x));
    res->Set(1, INT32(y));
#else
            v8::Local<v8::Array> res = v8::Array::New(2);
            res->Set(0, v8::Int32::New(x));
            res->Set(1, v8::Int32::New(y));
#endif

            info.GetReturnValue().Set(res);
    }

    NAN_METHOD(lcd128x64point) {
            SET_ARGUMENT_NAME(0, x);
            SET_ARGUMENT_NAME(1, y);
            SET_ARGUMENT_NAME(2, color);

            CHECK_ARGUMENTS_LENGTH_EQUAL(3);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);

            int x = GET_ARGUMENT_AS_INT32(0);
            int y = GET_ARGUMENT_AS_INT32(1);
            int color = GET_ARGUMENT_AS_INT32(2);

            ::lcd128x64point(x, y, color);
    }

    NAN_METHOD(lcd128x64line) {
            SET_ARGUMENT_NAME(0, x0);
            SET_ARGUMENT_NAME(1, y0);
            SET_ARGUMENT_NAME(2, x1);
            SET_ARGUMENT_NAME(3, y1);
            SET_ARGUMENT_NAME(4, color);

            CHECK_ARGUMENTS_LENGTH_EQUAL(5);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);
            CHECK_ARGUMENT_TYPE_INT32(3);
            CHECK_ARGUMENT_TYPE_INT32(4);

            int x0 = GET_ARGUMENT_AS_INT32(0);
            int y0 = GET_ARGUMENT_AS_INT32(1);
            int x1 = GET_ARGUMENT_AS_INT32(2);
            int y1 = GET_ARGUMENT_AS_INT32(3);
            int color = GET_ARGUMENT_AS_INT32(4);

            ::lcd128x64line(x0, y0, x1, y1, color);
    }

    NAN_METHOD(lcd128x64lineTo) {
            SET_ARGUMENT_NAME(0, x);
            SET_ARGUMENT_NAME(1, y);
            SET_ARGUMENT_NAME(2, color);

            CHECK_ARGUMENTS_LENGTH_EQUAL(3);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);

            int x = GET_ARGUMENT_AS_INT32(0);
            int y = GET_ARGUMENT_AS_INT32(1);
            int color = GET_ARGUMENT_AS_INT32(2);

            ::lcd128x64lineTo(x, y, color);
    }

    NAN_METHOD(lcd128x64rectangle) {
            SET_ARGUMENT_NAME(0, x1);
            SET_ARGUMENT_NAME(1, y1);
            SET_ARGUMENT_NAME(2, x2);
            SET_ARGUMENT_NAME(3, y2);
            SET_ARGUMENT_NAME(4, color);
            SET_ARGUMENT_NAME(5, filled);

            CHECK_ARGUMENTS_LENGTH_EQUAL(6);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);
            CHECK_ARGUMENT_TYPE_INT32(3);
            CHECK_ARGUMENT_TYPE_INT32(4);
            CHECK_ARGUMENT_TYPE_INT32(5);

            int x1 = GET_ARGUMENT_AS_INT32(0);
            int y1 = GET_ARGUMENT_AS_INT32(1);
            int x2 = GET_ARGUMENT_AS_INT32(2);
            int y2 = GET_ARGUMENT_AS_INT32(3);
            int color = GET_ARGUMENT_AS_INT32(4);
            int filled = GET_ARGUMENT_AS_INT32(5);

            ::lcd128x64rectangle(x1, y1, x2, y2, color, filled);
    }

    NAN_METHOD(lcd128x64circle) {
            SET_ARGUMENT_NAME(0, x);
            SET_ARGUMENT_NAME(1, y);
            SET_ARGUMENT_NAME(2, r);
            SET_ARGUMENT_NAME(3, color);
            SET_ARGUMENT_NAME(4, filled);

            CHECK_ARGUMENTS_LENGTH_EQUAL(5);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);
            CHECK_ARGUMENT_TYPE_INT32(3);
            CHECK_ARGUMENT_TYPE_INT32(4);

            int x = GET_ARGUMENT_AS_INT32(0);
            int y = GET_ARGUMENT_AS_INT32(1);
            int r = GET_ARGUMENT_AS_INT32(2);
            int color = GET_ARGUMENT_AS_INT32(3);
            int filled = GET_ARGUMENT_AS_INT32(4);

            ::lcd128x64circle(x, y, r, color, filled);
    }

    NAN_METHOD(lcd128x64ellipse) {
            SET_ARGUMENT_NAME(0, cx);
            SET_ARGUMENT_NAME(1, cy);
            SET_ARGUMENT_NAME(2, xRadius);
            SET_ARGUMENT_NAME(3, yRadius);
            SET_ARGUMENT_NAME(4, color);
            SET_ARGUMENT_NAME(5, filled);

            CHECK_ARGUMENTS_LENGTH_EQUAL(6);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);
            CHECK_ARGUMENT_TYPE_INT32(3);
            CHECK_ARGUMENT_TYPE_INT32(4);
            CHECK_ARGUMENT_TYPE_INT32(5);

            int cx = GET_ARGUMENT_AS_INT32(0);
            int cy = GET_ARGUMENT_AS_INT32(1);
            int xRadius = GET_ARGUMENT_AS_INT32(2);
            int yRadius = GET_ARGUMENT_AS_INT32(3);
            int color = GET_ARGUMENT_AS_INT32(4);
            int filled = GET_ARGUMENT_AS_INT32(5);

            ::lcd128x64ellipse(cx, cy, xRadius, yRadius, color, filled);
    }

    NAN_METHOD(lcd128x64putchar) {
            SET_ARGUMENT_NAME(0, x);
            SET_ARGUMENT_NAME(1, y);
            SET_ARGUMENT_NAME(2, c);
            SET_ARGUMENT_NAME(3, bgColor);
            SET_ARGUMENT_NAME(4, fgColor);

            CHECK_ARGUMENTS_LENGTH_EQUAL(5);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_INT32(2);
            CHECK_ARGUMENT_TYPE_INT32(3);
            CHECK_ARGUMENT_TYPE_INT32(4);

            int x = GET_ARGUMENT_AS_INT32(0);
            int y = GET_ARGUMENT_AS_INT32(1);
            int c = GET_ARGUMENT_AS_INT32(2);
            int bgColor = GET_ARGUMENT_AS_INT32(3);
            int fgColor = GET_ARGUMENT_AS_INT32(4);

            ::lcd128x64putchar(x, y, c, bgColor, fgColor);
    }

    NAN_METHOD(lcd128x64puts) {
            SET_ARGUMENT_NAME(0, x);
            SET_ARGUMENT_NAME(1, y);
            SET_ARGUMENT_NAME(2, string);
            SET_ARGUMENT_NAME(3, bgColor);
            SET_ARGUMENT_NAME(4, fgColor);

            CHECK_ARGUMENTS_LENGTH_EQUAL(5);

            CHECK_ARGUMENT_TYPE_INT32(0);
            CHECK_ARGUMENT_TYPE_INT32(1);
            CHECK_ARGUMENT_TYPE_STRING(2);
            CHECK_ARGUMENT_TYPE_INT32(3);
            CHECK_ARGUMENT_TYPE_INT32(4);

            int x = GET_ARGUMENT_AS_INT32(0);
            int y = GET_ARGUMENT_AS_INT32(1);
#if NODE_VERSION_AT_LEAST(0, 11, 0)
            v8::String::Utf8Value string(GET_ARGUMENT_AS_STRING(2));
#else
            v8::String::AsciiValue string(GET_ARGUMENT_AS_STRING(2));
#endif
            int bgColor = GET_ARGUMENT_AS_INT32(3);
            int fgColor = GET_ARGUMENT_AS_INT32(4);

            ::lcd128x64puts(x, y, *string, bgColor, fgColor);
    }

    NAN_METHOD(lcd128x64update) {
            CHECK_ARGUMENTS_LENGTH_EQUAL(0);

            ::lcd128x64update();
    }

    NAN_METHOD(lcd128x64clear) {
            SET_ARGUMENT_NAME(0, color);

            CHECK_ARGUMENTS_LENGTH_EQUAL(1);

            CHECK_ARGUMENT_TYPE_INT32(0);

            int color = GET_ARGUMENT_AS_INT32(0);

            ::lcd128x64clear(color);
    }

    NAN_METHOD(lcd128x64setup) {
            CHECK_ARGUMENTS_LENGTH_EQUAL(0);

            int res =::lcd128x64setup();

            info.GetReturnValue().Set(res);
    }

    NAN_MODULE_INIT(init_lcd128x64) {
            NAN_EXPORT(target, lcd128x64setOrigin);
            NAN_EXPORT(target, lcd128x64setOrientation);
            NAN_EXPORT(target, lcd128x64orientCoordinates);
            NAN_EXPORT(target, lcd128x64getScreenSize);
            NAN_EXPORT(target, lcd128x64point);
            NAN_EXPORT(target, lcd128x64line);
            NAN_EXPORT(target, lcd128x64lineTo);
            NAN_EXPORT(target, lcd128x64rectangle);
            NAN_EXPORT(target, lcd128x64circle);
            NAN_EXPORT(target, lcd128x64ellipse);
            NAN_EXPORT(target, lcd128x64putchar);
            NAN_EXPORT(target, lcd128x64puts);
            NAN_EXPORT(target, lcd128x64update);
            NAN_EXPORT(target, lcd128x64clear);
            NAN_EXPORT(target, lcd128x64setup);
    }
}