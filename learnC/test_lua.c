#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <stdio.h>

//初始化lua
lua_State*
initLuaEnv()
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    return L;
}

//加载lua主文件
int
loadLuaFile(lua_State* luaEnv,const char* fileName)
{
    int result = luaL_loadfile(luaEnv,fileName);
    if(result)
    {
        return result;
    }
    result = lua_pcall(luaEnv,1,0,1);
    return result;
}

int
main()
{
    lua_State *luaEnv = initLuaEnv();
    if(!luaEnv)
    {
        return -1;
    }
    if(!loadLuaFile(luaEnv,"./main.lua"))
    {
        printf("load lua main file Failed!");
        return -1;
    }
    lua_close(luaEnv);
    //printf("hello world\n");
    return 0;
}
