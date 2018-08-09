#include "Scenario.h"
#include "Curvature.h"

UScenario::UScenario(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{}

void UScenario::ResetAgents(const FKnowledgeBase& kb)
{
	_simulationTime = 0.f;
	for (auto&& agent : Agents)
	{
		agent->MoveToStartPosition(_random);

		agent->GenerateStartProperties(kb);
		agent->Properties.Reset();
		agent->Properties.Append(agent->StartProperties);
	}

	for (auto&& location : Locations)
	{
		location->GenerateStartProperties(kb);
		location->Properties.Reset();
		location->Properties.Append(location->StartProperties);
	}
}

void UScenario::Advance(float dt)
{
	_agentDecisions.Reset();
	_agentsActiveThisTick.Reset();
	_customActions.Reset();

	TArray<IScenarioMemberInterface*> targets;
	targets.Reserve(Agents.Num() + Locations.Num());
	targets.Append(Agents);
	targets.Append(Locations);

	for (auto&& agent : Agents)
	{
		auto decisionHistory = FScenarioAgent_DecisionHistory();
		const auto context = agent->ChooseBehavior(*this, targets, decisionHistory);
		if (context.IsSet())
		{
			ExecuteBehaviorOnAgent(context.GetValue(), dt);
		}
		else
		{
			agent->IsStalled = true;
		}
		decisionHistory.WinningContext = context;
		_agentDecisions.Add(agent, decisionHistory);
	}

	//SimulationAdvance(this)
	_simulationTime += dt;
}
