#pragma once 


#include "ScenarioAgent_DecisionHistory.generated.h"

//struct FScenario_Context;

USTRUCT(BlueprintType)
struct CURVATURE_API FScenarioAgent_DecisionHistory
{
    GENERATED_BODY()
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite) *///TArray<FScenario_Context> ScoredContexts;
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite)*/ //TOptional<FScenario_Context> WinningContext;
};