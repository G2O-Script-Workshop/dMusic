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
	// g2o uses dynamic hooks (once that revert patch to original value & invoke the original function), tso we need to follow this pattern here
	Hook_oCGame_Render.Disable();

	printf("render call\n");

	// always invoke original method! (calling overloaded union call operator on Hook_oCGame_Render will result in a crash)
	self->Render();

	// if we want to keep our hook active, we need to reapply it
	Hook_oCGame_Render.Enable();
}

extern "C" SQRESULT SQRAT_API sqmodule_load(HSQUIRRELVM vm, HSQAPI api)
{
	SqModule::Initialize(vm, api);

	return SQ_OK;
}
