#define EXTENSION_NAME PlatformUUID
#define LIB_NAME "PlatformUUID"
#define MODULE_NAME "platform_uuid"
#define DLIB_LOG_DOMAIN LIB_NAME

#include <dmsdk/sdk.h>
#include "platform_uuid.h"

static int Lua_GetPlatformUUID(lua_State* L) {

#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX) || defined(DM_PLATFORM_ANDROID) || defined(__EMSCRIPTEN__)
    return GetPlatformUUID(L);
#endif
    lua_pushnil(L);
    return 1;
}

static const luaL_reg Module_methods[] =
{
    {"get_uuid", Lua_GetPlatformUUID},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);
    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result InitializePlatformUUID(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    #if defined(DM_PLATFORM_ANDROID) 
        Initialize_Ext();
    #endif
    return dmExtension::RESULT_OK;
}


DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, 0, 0, InitializePlatformUUID, 0, 0, 0)
