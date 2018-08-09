#pragma once

#include "Consideration.h"
#include "Scenarios/Scenario_ConsiderationScore.h"

#include "HGUtilities/EnumUtils.h"

#include "Behavior.generated.h"

class IInputBrokerInterface;

UENUM(BlueprintType)
enum class EActionType : uint8
{
    Idle UMETA(DisplayName="Do nothing"),
    MoveToTarget,
    MoveAwayFromTarget,
    Talk UMETA("Show a speech ballon"),
    Custom UMETA("Show a custom animation")
};

DEFINE_ENUM_TO_STRING(EActionType);

USTRUCT(BlueprintType)
struct CURVATURE_API FBehavior
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName ReadableName;
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility)*/ TArray<FConsideration> Considerations;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float Weight = 1.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) EActionType Action = EActionType::Idle;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) bool CanTargetSelf = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) bool CanTargetOthers = true;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FString Payload;

	FString ToString() const;

	FScenario_ConsiderationScores Score(IInputBrokerInterface* broker, const FScenario_Context& context);

	bool operator==(const FBehavior& other) const
	{
		return ReadableName == other.ReadableName
            && Considerations.Num() == other.Considerations.Num() // an approximation
            && FMath::IsNearlyEqual(Weight, other.Weight) 
            && Action == other.Action
            && CanTargetSelf == other.CanTargetSelf
            && CanTargetOthers == other.CanTargetOthers
            && Payload == other.Payload;
	}

	friend FORCEINLINE static uint32 GetTypeHash(const FBehavior& behavior)
	{
		const auto nameHash = GetTypeHash(behavior.ReadableName);
		const auto weightHash = GetTypeHash(behavior.Weight);
		const auto actionHash = GetTypeHash(static_cast<uint8>(behavior.Action));
		//todo: better hashing
		return HashCombine(HashCombine(nameHash, weightHash), actionHash);
	}
};