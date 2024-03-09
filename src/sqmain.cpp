#include <sqapi.h>
#include <Union/Hook.h>
#include <ZenGin/zGothicAPI.h>

using namespace Gothic_II_Addon;

/* squirreldoc (func)
*
* This is is an example hook for oCGame::Render method.
*
* @version	0.1
* @side		client
* @name		oCGame__Render
* @param	(oCGame*) self the oCGame ptr to object instance.
* @param	(void*) vtable the vftable param.
*
*/
void __fastcall oCGame__Render(oCGame* self, void* vtable);
auto Hook_oCGame_Render = Union::CreateHook((void*)0x006C86A0, oCGame__Render, Union::HookType::Hook_Detours);
void __fastcall oCGame__Render(oCGame* self, void* vtable)
{
	printf("render call\n");
	Hook_oCGame_Render(self, vtable);

	// Since g2o hook is overriding Union master hook, we need to reapply it
	Hook_oCGame_Render.Disable();
	Hook_oCGame_Render.Enable();
}

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	SqModule::Initialize(vm, api);

	return SQ_OK;
}
