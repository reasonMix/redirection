#include "lua_redirection.hpp"
#include <stdio.h>
#include <unistd.h>

static int temp_stdout;
static int redirection_enable(lua_State* L) {
	temp_stdout = dup(1);

	const char* fileName = lua_tostring(L, 1);
	freopen(fileName, "w", stdout);
	printf("enable the %s redirection",fileName);
	return 0;
}

static int redirection_disable(lua_State* L) {
	freopen( "/dev/tty", "w", stdout );
	printf("disable the redirection");
	return 0;
}

static luaL_Reg api[] = {
    { "enable", redirection_enable },
    { "disable", redirection_disable},
    { NULL, NULL },
};

int luaopen_redirection(lua_State* L)
{
  // register the net api
  lua_newtable(L);
  luaL_register(L, NULL, api);

  return 1;
}
