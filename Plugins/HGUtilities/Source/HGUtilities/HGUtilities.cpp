#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "HGUtilities.h"

DEFINE_LOG_CATEGORY(HGUtilities)

class FHGUtilities : public IHGUtilities
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FHGUtilities, HGUtilities )



void FHGUtilities::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FHGUtilities::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



