#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleManager.h"



DECLARE_LOG_CATEGORY_EXTERN(LogHW_Puzzle, Log, All);



class FHW_PuzzleModule : public IModuleInterface

{

public:



	/** IModuleInterface implementation */

	virtual void StartupModule() override;

	virtual void ShutdownModule() override;

};
