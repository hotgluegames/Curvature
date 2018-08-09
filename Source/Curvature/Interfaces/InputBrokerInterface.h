#pragma once

#include "InputBrokerInterface.generated.h"

UINTERFACE(BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class CURVATURE_API UInputBrokerInterface : public UInterface
{
    GENERATED_UINTERFACE_BODY()
};

struct FConsideration;
struct FScenario_Context;

class CURVATURE_API IInputBrokerInterface
{
    GENERATED_IINTERFACE_BODY()

public:
    virtual float GetInputValue(const FConsideration& consideration) const = 0;
    virtual float GetInputValue(const FConsideration& consideration, const FScenario_Context& context) const = 0;
    void RefreshInputs();
};