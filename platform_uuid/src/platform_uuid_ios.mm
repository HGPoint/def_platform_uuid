#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX) 

#include <Foundation/Foundation.h>

#include <dmsdk/sdk.h>

int GetPlatformUUID(lua_State* L)
{
    lua_pushstring(L, [[[NSUUID UUID] UUIDString] UTF8String]);
    return 1;
}
#endif