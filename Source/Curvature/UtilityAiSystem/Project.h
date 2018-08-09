#pragma once

#include "Archetype.h"
#include "Behavior.h"
#include "BehaviorSet.h"
#include "InputAxis.h"
#include "Scenarios/Scenario.h"
#include "Knowledgebase.h"

#include "Project.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FCurvatureProject
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName ReadableName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FKnowledgeBase KB;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) TArray<FArchetype> Archetypes;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) TArray<FBehavior> Behavior;

    
};