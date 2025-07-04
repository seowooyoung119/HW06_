#include "HW_Player.h"



DEFINE_LOG_CATEGORY(LogHW_Player);



#define LOCTEXT_NAMESPACE "FHW_PlayerModule"



void FHW_PlayerModule::StartupModule()

{

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(LogHW_Player, Warning, TEXT("HW_Player module has been loaded!"));

}



void FHW_PlayerModule::ShutdownModule()

{

	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,

	// we call this function before unloading the module.

	UE_LOG(LogHW_Player, Warning, TEXT("HW_Player module has been unloaded!"));

}



#undef LOCTEXT_NAMESPACE



IMPLEMENT_MODULE(FHW_PlayerModule, HW_Player)
