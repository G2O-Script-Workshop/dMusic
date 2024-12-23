#pragma once

#include <sqapi.h>

#include <ZenGin/zGothicAPI.h>
#define ENGINE Engine_G2A

using namespace Gothic_II_Addon;

SQRESULT sq_arrayappend_integer(HSQUIRRELVM vm, SQInteger val);

SQRESULT sq_newslot_bool(HSQUIRRELVM vm, const SQChar* idx, SQBool val);
SQRESULT sq_newslot_integer(HSQUIRRELVM vm, const SQChar* idx, SQInteger val);
SQRESULT sq_newslot_float(HSQUIRRELVM vm, const SQChar* idx, SQFloat val);
SQRESULT sq_newslot_string(HSQUIRRELVM vm, const SQChar* idx, const SQChar* val);

SQRESULT sq_pushvec3(HSQUIRRELVM vm, SQFloat x, SQFloat y, SQFloat z);

SQRESULT sq_get_float(HSQUIRRELVM vm, SQInteger idx, const SQChar* key, SQFloat* f);
