#include "HW_Puzzle.h"



DEFINE_LOG_CATEGORY(LogHW_Puzzle);



#define LOCTEXT_NAMESPACE "FHW_PuzzleModule"



void FHW_PuzzleModule::StartupModule()

{

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(LogHW_Puzzle, Warning, TEXT("HW_Puzzle module has been loaded!"));

}



void FHW_PuzzleModule::ShutdownModule()

{

	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,

	// we call this function before unloading the module.

	UE_LOG(LogHW_Puzzle, Warning, TEXT("HW_Puzzle module has been unloaded!"));

}



#undef LOCTEXT_NAMESPACE



IMPLEMENT_MODULE(FHW_PuzzleModule, HW_Puzzle)
