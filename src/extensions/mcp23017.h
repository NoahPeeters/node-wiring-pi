#ifndef _WPI_MCP23017_H_
#define _WPI_MCP23017_H_

#include "../addon.h"

namespace nodewpi {
  NAN_METHOD(mcp23017Setup);

  NAN_MODULE_INIT(init_mcp23017);
}

#endif