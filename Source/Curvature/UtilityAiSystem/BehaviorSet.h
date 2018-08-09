#pragma once

#include "Behavior.h"
#include "BehaviorSet.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FBehaviorSet
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) TSet<FBehavior> EnabledBehaviors;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName ReadableName;
    
    FBehaviorSet() = default;
    FBehaviorSet(FName name) : ReadableName(name) {}

    FString ToString() const {return ReadableName.ToString();}
    void Rename(FName name) {ReadableName = name;}
    FName GetName() const {return ReadableName;}
};