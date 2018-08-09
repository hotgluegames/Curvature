#pragma once
#include "RenameableInterface.generated.h"

UINTERFACE(BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class CURVATURE_API URenameableInterface : public UInterface
{
    GENERATED_UINTERFACE_BODY()
};
class CURVATURE_API IRenameableInterface
{
    GENERATED_IINTERFACE_BODY()
    virtual FName GetName() const = 0;
    virtual void Rename(FName string) = 0;
};