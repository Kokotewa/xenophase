#include "Globals.h" // g_fileMgr
#include "Lua.h"
#include "Base/File.h"
#include "Base/FileMgr.h"
////////////////////////////////////////


//#include <lua.h>
typedef struct lua_State lua_State;
typedef double lua_Number;
#define LUA_REGISTRYINDEX	(-10000)
#define LUA_ENVIRONINDEX	(-10001)
#define LUA_GLOBALSINDEX	(-10002)


#define lua_open()	luaL_newstate()
#define lua_pop(L,n)		lua_settop(L, -(n)-1)


hook_func<lua_State* (__cdecl *)()> _luaL_newstate("luaL_newstate");
lua_State* luaL_newstate()
{
	return _luaL_newstate();
}


hook_func<void (__cdecl *)(lua_State* L)> _lua_close("lua_close");
void lua_close(lua_State* L)
{
	return _lua_close(L);
}


hook_func<void (__cdecl *)(lua_State* L, int index, const char* k)> _lua_getfield("lua_getfield");
void lua_getfield(lua_State* L, int index, const char* k)
{
	return _lua_getfield(L, index, k);
}


hook_func<int (__cdecl *)(lua_State* L)> _lua_gettop("lua_gettop");
int lua_gettop(lua_State* L)
{
	return _lua_gettop(L);
}


hook_func<void (__cdecl *)(lua_State* L, int index)> _lua_settop("lua_settop");
void lua_settop(lua_State* L, int index)
{
	return _lua_settop(L, index);
}


hook_func<void (__cdecl *)(lua_State* L, int index)> _lua_gettable("lua_gettable");
void lua_gettable(lua_State* L, int index)
{
	return _lua_gettable(L, index);
}


hook_func<int (__cdecl *)(lua_State* L, int nargs, int nresults, int errfunc)> _lua_pcall("lua_pcall");
int lua_pcall(lua_State* L, int nargs, int nresults, int errfunc)
{
	return _lua_pcall(L, nargs, nresults, errfunc);
}


hook_func<void (__cdecl *)(lua_State* L, lua_Number n)> _lua_pushnumber("lua_pushnumber");
void lua_pushnumber(lua_State* L, lua_Number n)
{
	return _lua_pushnumber(L, n);
}


hook_func<void (__cdecl *)(lua_State* L, const char* s)> _lua_pushstring("lua_pushstring");
void lua_pushstring(lua_State* L, const char* s)
{
	return _lua_pushstring(L, s);
}


hook_func<void (__cdecl *)(lua_State* L, int b)> _lua_pushboolean("lua_pushboolean");
void lua_pushboolean(lua_State* L, int b)
{
	return _lua_pushboolean(L, b);
}


hook_func<lua_Number (__cdecl *)(lua_State* L, int index)> _lua_tonumber("lua_tonumber");
lua_Number lua_tonumber(lua_State* L, int index)
{
	return _lua_tonumber(L, index);
}


hook_func<const char* (__cdecl *)(lua_State* L, int index, size_t* len)> _lua_tolstring("lua_tolstring");
const char* lua_tolstring(lua_State* L, int index, size_t* len)
{
	return _lua_tolstring(L, index, len);
}


hook_func<int (__cdecl *)(lua_State* L, int index)> _lua_toboolean("lua_toboolean");
int lua_toboolean(lua_State* L, int index)
{
	return _lua_toboolean(L, index);
}


hook_func<void (__cdecl *)(lua_State* L, int sz, const char* msg)> _luaL_checkstack("luaL_checkstack");
void luaL_checkstack(lua_State* L, int sz, const char* msg)
{
	return _luaL_checkstack(L, sz, msg);
}


hook_func<int (__cdecl *)(lua_State* L, const char* buff, size_t sz, const char* name)> _luaL_loadbuffer("luaL_loadbuffer");
int luaL_loadbuffer(lua_State* L, const char* buff, size_t sz, const char* name)
{
	return _luaL_loadbuffer(L, buff, sz, name);
}


hook_func<void (__cdecl *)(lua_State* L)> _luaL_openlibs("luaL_openlibs");
void luaL_openlibs(lua_State* L)
{
	return _luaL_openlibs(L);
}


////////////////////////////////////////


CLua::CLua()
{
	m_LuaState = NULL;
}


CLua::~CLua()
{
	this->CLua::Destroy();
}


void CLua::Init()
{
	if( m_LuaState != NULL )
	{
		lua_close(m_LuaState);
		m_LuaState = NULL;
	}

	m_LuaState = lua_open();

	if( m_LuaState != NULL )
	{
		luaL_openlibs(m_LuaState);
		this->CLua::RegisterFuncs();
	}
}


void CLua::Destroy()
{
	if( m_LuaState != NULL )
	{
		lua_close(m_LuaState);
		m_LuaState = NULL;
	}
}


hook_func<void (CLua::*)()> CLua__RegisterFuncs("CLua::RegisterFuncs");
void CLua::RegisterFuncs()
{
	return (this->*CLua__RegisterFuncs)();

	//TODO
}


void CLua::ErrorMsg(const char* caption, const char* fmt, ...)
{
	va_list va;
	va_start(va, fmt);

	char message[500];
	vsprintf(message, fmt, va);

	MessageBoxA(NULL, message, caption, MB_OK);
}


bool CLua::Load(const char* filename, bool bMakeDataPath, bool bReadFolderOnly)
{
	if( m_LuaState == NULL )
		return false;

	mystd::string baseDir = "";
	if( !bReadFolderOnly )
		baseDir = "LuaFiles514\\";

	mystd::string filepath = baseDir + filename + ".lub";
	if( bMakeDataPath )
	{
		if( !CFile::IsFileExist(filepath.c_str(), bReadFolderOnly) )
		{
			filepath = baseDir + filename + ".lua";
			if( !CFile::IsFileExist(filepath.c_str(), bReadFolderOnly) )
				return false;
		}
	}
	else
	{
		if( !g_fileMgr.CFileMgr::IsDataExist(filepath.c_str(), bReadFolderOnly) )
		{
			filepath = baseDir + filename + ".lua";
			if( !g_fileMgr.CFileMgr::IsDataExist(filepath.c_str(), bReadFolderOnly) )
				return false;
		}
	}

	CFile f;
	if( !f.CFile::Open(filepath.c_str(), CFile::modeRead, bMakeDataPath, bReadFolderOnly) )
		return false;

	DWORD bufsize = f.CFile::GetLength();
	char* buf = new char[bufsize + 1];

	f.CFile::Read(buf, bufsize);
	buf[bufsize] = '\0';

	f.CFile::Close();

	if( luaL_loadbuffer(m_LuaState, buf, bufsize, "buf") || lua_pcall(m_LuaState, 0, 0, 0) )
	{
		const char* msg = lua_tolstring(m_LuaState, -1, NULL);
		this->CLua::ErrorMsg(filename, "%s\n", msg);
		lua_settop(m_LuaState, -2);

		delete[] buf;
		return false;
	}

	delete[] buf;
	return true;
}


bool CLua::Execute(mystd::string funcname, const char* argfmt, ...)
{
	if( m_LuaState == NULL )
		return false;

	lua_getfield(m_LuaState, LUA_GLOBALSINDEX, funcname.c_str());

	va_list va;
	va_start(va, argfmt);

	const char* pfmt = argfmt;
	int in_count = 0;

	while( *pfmt != '\0' )
	{
		luaL_checkstack(m_LuaState, 1, "too many arguments");

		char type = *pfmt++;
		if( type == '>' )
			break;

		switch( type )
		{
		case 'b':
		{// boolean
			bool val = va_arg(va, bool);
			lua_pushboolean(m_LuaState, val);
		}
		break;
		case 'd':
		{// integer
			int val = va_arg(va, int);
			lua_pushnumber(m_LuaState, val);
		}
		break;
		case 'l':
		{// double
			double val = va_arg(va, double);
			lua_pushnumber(m_LuaState, val);
		}
		break;
		case 's':
		{// string
			const char* val = va_arg(va, const char*);
			lua_pushstring(m_LuaState, val);
		}
		break;
		default:
		{// unsupported
			this->CLua::ErrorMsg(funcname.c_str(), "invalid option (%c)", type);
		}
		break;
		};

		++in_count;
	};

	int out_count = strlen(pfmt);

	if( lua_pcall(m_LuaState, in_count, out_count, 0) != 0 )
	{
		const char* errmsg = lua_tolstring(m_LuaState, -1, NULL);
		this->CLua::ErrorMsg(funcname.c_str(), "%s\n", errmsg);

		if( m_LuaState != NULL )
			lua_settop(m_LuaState, 0);

		return false;
	}

	if( out_count == 0 )
		return true; // done.

	int index = -out_count;

	while( *pfmt != '\0' )
	{
		char type = *pfmt++;

		switch( type )
		{
		case 'b':
		{// boolean
			bool* val = va_arg(va, bool*);
			*val = ( lua_toboolean(m_LuaState, index) != 0 );
		}
		break;
		case 'd':
		{// integer
			int* val = va_arg(va, int*);
			*val = (int)lua_tonumber(m_LuaState, index);
		}
		break;
		case 'l':
		{// double
			double* val = va_arg(va, double*);
			*val = lua_tonumber(m_LuaState, index);
		}
		break;
		case 's':
		{// string
			const char** val = va_arg(va, const char**);
			*val = lua_tolstring(m_LuaState, index, NULL);
		}
		break;
		default:
		{// unsupported
			this->CLua::ErrorMsg(funcname.c_str(), "invalid option (%c)", type);
		}
		break;
		};

		++index;
	};

	lua_pop(m_LuaState, out_count);

	if( m_LuaState != NULL )
		lua_settop(m_LuaState, 0);

	return true;
}


////////////////////////////////////////
