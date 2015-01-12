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
    if(result == LUA_ERRSYNTAX)
    {
        printf("无法错误");
    }
    //lua_resume(luaEnv,0);
    int top = lua_gettop(luaEnv);
    printf("top is %d \n",top);
    lua_getglobal(luaEnv,"test");
    printf("type:%d \n",lua_type(luaEnv,-1));
    if(lua_type(luaEnv,-1) != LUA_TFUNCTION)
    {
        printf("can't find function error");
        lua_settop(luaEnv,top);
        return -1;
    }

    int errfunc = lua_gettop(luaEnv);
    if(result)
    {
        return result;
    }
    //result = lua_pcall(luaEnv,1,0,1);
    lua_getglobal(luaEnv,"main");
    if(lua_type(luaEnv,-1) != LUA_TFUNCTION)
    {
        printf("can't find function main");
        lua_settop(luaEnv,top);
        return -1;
    }
    if(lua_pcall(luaEnv,0,0,errfunc) !=0)
    {
        printf("can't call function main");
        lua_settop(luaEnv,top);
        return -1;
    }
    
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
