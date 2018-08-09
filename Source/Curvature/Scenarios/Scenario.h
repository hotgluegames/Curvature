#pragma once
#include "Interfaces/RenameableInterface.h"
#include "Interfaces/InputBrokerInterface.h"
#include "Interfaces/ScenarioMemberInterface.h"

#include "UtilityAiSystem/Consideration.h"

#include "ScenarioAgent.h"
#include "ScenarioLocation.h"

#include "ScenarioAgent_DecisionHistory.h"
#include "Scenario.generated.h"

UCLASS(BlueprintType, ClassGroup="AI|Curvature")
class CURVATURE_API UScenario : public UObject, public IRenameableInterface, public IInputBrokerInterface
{
	GENERATED_BODY()
private:
	float _horizontalUnitsVisible = 2.f;
	float _verticalUnitsVisible = 2.f;
	float _horizontalUnitsOffset = 0.5f;
	float _verticalUnitsOffset = 0.5f;

	FRandomStream _random;

	TSet<TWeakObjectPtr<UScenarioAgent>> _agentsActiveThisTick;
	TMap<UScenarioAgent*, FScenarioAgent_DecisionHistory> _agentDecisions;
	TArray<FScenario_Context> _customActions;

	float _simulationTime = 0.f;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName ReadableName;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite) */TArray<UScenarioAgent*> Agents;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)*/ TArray<UScenarioLocation*> Locations;

	UScenario(const FObjectInitializer& objectInitializer);

	void Initialize(FName name)
	{
		ReadableName = name;
		//        InitializeDrawingResources();
		unimplemented();
	}

	void ReseedRandoms(int32 seed)
	{
		_random.Initialize(seed);
	}

	void ReseedRandoms()
	{
		_random.GenerateNewSeed();
	}

	void ResetAgents(const FKnowledgeBase& kb);

	void Advance(float dt);

	FName GetName() const override {return ReadableName;}
	void Rename(FName name) override {ReadableName = name;}

	float GetInputValue(const FConsideration& consideration) const {unimplemented(); return 0;}
	float GetInputValue(const FConsideration& consideration, const FScenario_Context& context) const {unimplemented(); return 0;}

private:
	void ExecuteBehaviorOnAgent(const FScenario_Context& context, float dt)
	{
		unimplemented();
	}
};
