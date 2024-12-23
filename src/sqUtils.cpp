#include "sqUtils.h"

SQRESULT sq_arrayappend_integer(HSQUIRRELVM vm, SQInteger val)
{
	sq_pushinteger(vm, val);
	return sq_arrayappend(vm, -1);
}

SQRESULT sq_newslot_bool(HSQUIRRELVM vm, const SQChar* idx, SQBool val)
{
	sq_pushstring(vm, idx, -1);
	sq_pushbool(vm, val);
	return sq_newslot(vm, -3, SQFalse);
}

SQRESULT sq_newslot_integer(HSQUIRRELVM vm, const SQChar* idx, SQInteger val)
{
	sq_pushstring(vm, idx, -1);
	sq_pushinteger(vm, val);
	return sq_newslot(vm, -3, SQFalse);
}

SQRESULT sq_newslot_float(HSQUIRRELVM vm, const SQChar* idx, SQFloat val)
{
	sq_pushstring(vm, idx, -1);
	sq_pushfloat(vm, val);
	return sq_newslot(vm, -3, SQFalse);
}

SQRESULT sq_newslot_string(HSQUIRRELVM vm, const SQChar* idx, const SQChar* val)
{
	sq_pushstring(vm, idx, -1);
	sq_pushstring(vm, val, -1);
	return sq_newslot(vm, -3, SQFalse);
}

SQRESULT sq_pushvec3(HSQUIRRELVM vm, SQFloat x, SQFloat y, SQFloat z)
{
	SQInteger top = sq_gettop(vm);

	// push class reference onto the stack
	sq_pushroottable(vm);
	sq_pushstring(vm, "Vec3", -1);
	if (SQ_FAILED(sq_get(vm, -2)))
	{
		sq_settop(vm, top);
		return SQ_ERROR;
	}

	// remove the roottable reference from the stack
	sq_remove(vm, -2);

	// push class instance onto a stack
	sq_createinstance(vm, -1);

	// remove the class reference from the stack
	sq_remove(vm, -2);

	// push the constructor method onto a stack
	sq_pushstring(vm, "constructor", -1);
	if (SQ_FAILED(sq_get(vm, -2)))
	{
		sq_settop(vm, top);
		return SQ_ERROR;
	}

	// invoke the constructor
	sq_push(vm, -2);
	sq_pushfloat(vm, x);
	sq_pushfloat(vm, y);
	sq_pushfloat(vm, z);
	if (SQ_FAILED(sq_call(vm, 4, SQFalse, SQFalse)))
	{
		sq_settop(vm, top);
		return SQ_ERROR;
	}

	// remove the constructor method from the stack
	sq_remove(vm, -1);

	return SQ_OK;
}

SQRESULT sq_get_float(HSQUIRRELVM vm, SQInteger idx, const SQChar* key, SQFloat* f)
{
	sq_pushstring(vm, key, -1);
	if (SQ_FAILED(sq_get(vm, idx)))
	{
		std::string errorMessage = "the index '";
		errorMessage += key;
		errorMessage += "' does not exist";

		return sq_throwerror(vm, errorMessage.c_str());
	}

	if (SQ_FAILED(sq_getfloat(vm, -1, f)))
	{
		std::string errorMessage = "the value under index '";
		errorMessage += key;
		errorMessage += "' is not a float";

		return sq_throwerror(vm, errorMessage.c_str());
	}

	return SQ_OK;
}