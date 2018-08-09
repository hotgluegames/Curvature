#pragma once

#include "Interfaces/ScenarioMemberInterface.h"

#include "UtilityAiSystem/Behavior.h"
#include "Scenario_ConsiderationScore.h"

#include "ScenarioAgent.h"
#include "Scenario_Context.generated.h"


USTRUCT(BlueprintType)
struct CURVATURE_API FScenario_Context
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) UScenarioAgent* ThinkingAgent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TScriptInterface<IScenarioMemberInterface> Target;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FBehavior ChosenBehavior;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FScenario_ConsiderationScores BehaviorScore;
    FString ToString() const
    {
        return FString::Format(TEXT("Target: {0}\r\nBehavior: {1} [{2}]\r\n{3}"), {
            Target->GetName().ToString(),
            ChosenBehavior.ToString(),
            TEXT("unimplemented"),//ChosenBehavior.Action.ToString(),
            BehaviorScore.ToString()
        });
    }
};