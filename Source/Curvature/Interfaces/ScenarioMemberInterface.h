#pragma once
#include "ScenarioMemberInterface.generated.h"

struct FKnowledgeBase_Record;

UINTERFACE(BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class CURVATURE_API UScenarioMemberInterface : public UInterface
{
    GENERATED_UINTERFACE_BODY()
};

class CURVATURE_API IScenarioMemberInterface
{
    GENERATED_IINTERFACE_BODY()
public:
    virtual FName GetName() const = 0;
    virtual FVector GetPosition() const = 0;
    virtual UObject* GetProperty(const FKnowledgeBase_Record& kbrec) const = 0;
    virtual float GetRadius() const = 0;
};