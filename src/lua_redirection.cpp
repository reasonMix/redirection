#include "lua_redirection.hpp"
#include <stdio.h>

static int redirection_enable(lua_State* L) {
	const char* fileName = lua_tostring(L, 1);
	freopen(fileName, "w", stdout);
	printf("enable the %s redirection",fileName);
	return 0;
}

static int redirection_disable(lua_State* L) {
	freopen("CON", "w", stdout);
	printf("disable the redirection");
	return 0;
}

static luaL_Reg api[] = {
    { "enable", redirection_enable },
    { "disable", redirection_disable},
    { NULL, NULL },
};

int luaopen_netfoxpack(lua_State* L)
{
  // register the net api
  lua_newtable(L);
  luaL_register(L, NULL, api);

  return 1;
}
