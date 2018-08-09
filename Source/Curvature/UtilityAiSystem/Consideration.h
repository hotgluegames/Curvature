#pragma once

#include "InputAxis.h"
#include "ResponseCurve.h"
#include "Scenarios/Scenario_Score.h"

#include "Consideration.generated.h"

//struct FScenario_Context;
class IInputBrokerInterface;
USTRUCT(BlueprintType)
struct CURVATURE_API FConsideration
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName ReadableName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FInputAxis Input;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FResponseCurve Curve;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility)*/TArray<FInputParameterValue> ParameterValues;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) bool WrapInput = false;

	FConsideration();

	FConsideration(const FName& readableName, FInputAxis&& input, const FResponseCurve& curve,
	               const TArray<FInputParameterValue>& parameterValues, bool wrapInput);

	void GenerateParameterValuesFromInput();

	//FScenario_Score Score(IInputBrokerInterface& broker, const FScenario_Context& context);

	bool operator==(const FConsideration& src) const 
	{
		return ReadableName == src.ReadableName;
	}

	friend FORCEINLINE static uint32 GetTypeHash(const FConsideration& consideration)
	{
		return GetTypeHash(consideration.ReadableName);
	}

private:
	float NormalizeInput(float raw);
};


