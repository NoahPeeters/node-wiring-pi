#ifndef _WPI_MCP23S08_H_
#define _WPI_MCP23S08_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(mcp23s08Setup);

  NAN_MODULE_INIT(init_mcp23s08);
}

#endif