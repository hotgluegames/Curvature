#pragma once

#include "Optional.h"

#include "Interfaces/InputBrokerInterface.h"
#include "Interfaces/ScenarioMemberInterface.h"

#include "UtilityAiSystem/KnowledgeBase.h"
#include "UtilityAiSystem/Archetype.h"

#include "ScenarioLocation.h"
#include "ScenarioAgent_DecisionHistory.h"

#include "ScenarioAgent.generated.h"

UCLASS()
class CURVATURE_API UScenarioAgent : public UObject, public IScenarioMemberInterface
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category=ScenarioMember) FName Name;
	UPROPERTY(EditAnywhere, Category=ScenarioMember) FVector Position;
	UPROPERTY(EditAnywhere, Category=ScenarioMember) FVector StartPosition;
	UPROPERTY(EditAnywhere, Category=ScenarioMember) float Radius = 1.f;
	UPROPERTY(EditAnywhere, Category=ScenarioMember) TMap<FKnowledgeBase_Record, UObject*> Properties;
	UPROPERTY(EditAnywhere, Category=ScenarioMember) TMap<FKnowledgeBase_Record, UObject*> StartProperties;
	/*UPROPERTY(EditAnywhere, Instanced, Category=ScenarioMember)*/ FArchetype AgentArchetype;
	UPROPERTY(EditAnywhere, Category=ScenarioMember) FColor Color = FColor::Blue;
	/*UPROPERTY(EditAnywhere, Instanced, Category=ScenarioMember)*/ UScenarioLocation* ScenarioLocation;
	UPROPERTY(EditAnywhere, Category=ScenarioMember) bool StartFuzzed;

	TWeakObjectPtr<IScenarioMemberInterface> Intent;
	uint8 IsStalled : 1;
	uint8 IntentActive : 1;

	void Initialize(FName name, FArchetype archetype)
	{
		Name = name;
		AgentArchetype = archetype;
	}

	FName GetName() const override
	{
		return Name;
	}

	FVector GetPosition() const override
	{
		return Position;
	}

	float GetRadius() const
	{
		return Radius;
	}

	UObject* GetProperty(const FKnowledgeBase_Record& kbrec) const
	{
		return Properties.Contains(kbrec) ? Properties[kbrec] : nullptr;
	}


	TOptional<FScenario_Context> ChooseBehavior(IInputBrokerInterface& broker,
	                                            TArray<IScenarioMemberInterface*> targets,
	                                            FScenarioAgent_DecisionHistory& scores);


	UObject* GetProperty(const FKnowledgeBase_Record& kbrec)
	{
		unimplemented();
		return nullptr;
	}

	void GenerateStartProperties(const FKnowledgeBase& kb)
	{
		unimplemented();
	}

	void MoveToStartPosition(const FRandomStream& random)
	{
		unimplemented();
	}

protected:
    
    
private:
    
};