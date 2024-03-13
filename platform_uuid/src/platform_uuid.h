
#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX) || defined(DM_PLATFORM_ANDROID) || defined(__EMSCRIPTEN__)

#pragma once
#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_ANDROID) 
void Initialize_Ext();
#endif

int GetPlatformUUID(lua_State* L);

#endif