#pragma once

#include "Modules/ModuleManager.h"

class FHW_SystemModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
