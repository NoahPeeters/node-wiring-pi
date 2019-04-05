#ifndef _WPI_MCP23016_H_
#define _WPI_MCP23016_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(mcp23016Setup);

  NAN_MODULE_INIT(init_mcp23016);
}

#endif