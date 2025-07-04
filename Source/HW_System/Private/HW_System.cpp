#include "HW_System.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FHW_SystemModule"

void FHW_SystemModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Log, TEXT("HW_System module has been loaded!"));
}

void FHW_SystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(LogTemp, Log, TEXT("HW_System module has been unloaded!"));
}

#undef LOCTEXT_NAMESPACE	
IMPLEMENT_MODULE(FHW_SystemModule, HW_System)
