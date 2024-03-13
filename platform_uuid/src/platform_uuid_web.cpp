#if defined(__EMSCRIPTEN__)

#include "platform_uuid_web_api.h"

#include <dmsdk/sdk.h>

int GetPlatformUUID(lua_State* L)
{
    lua_pushstring(L, GetWebUUID());
    return 1;
}

#endif