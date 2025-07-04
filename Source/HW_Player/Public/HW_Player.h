#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleManager.h"



DECLARE_LOG_CATEGORY_EXTERN(LogHW_Player, Log, All);



class FHW_PlayerModule : public IModuleInterface

{

public:



	/** IModuleInterface implementation */

	virtual void StartupModule() override;

	virtual void ShutdownModule() override;

};
