#if __G2A && SCRAT_EXPORT

// #include "sqUtils.h"
#include "sqFunction.h"

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	SqModule::Initialize(vm, api);
	Sqrat::DefaultVM::Set(vm);


	Sqrat::RootTable(vm)
		.Func("playTheme", &sq_playTheme)
		.Func("stopTheme", &sq_stopTheme);

		return SQ_OK;
}

#endif