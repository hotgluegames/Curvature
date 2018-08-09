#include "ScenarioAgent.h"
#include "Curvature.h"

TOptional<FScenario_Context> UScenarioAgent::ChooseBehavior(IInputBrokerInterface& broker,
                                                            TArray<IScenarioMemberInterface*> targets,
                                                            FScenarioAgent_DecisionHistory& scores)
{
	checkSlow(Algo::NoneOf(targets, [](auto* x){return x == nullptr;}));

	for (auto&& set : AgentArchetype.BehaviorSets)
	{
		for (auto&& behavior : set.EnabledBehaviors)
		{
			if (behavior.CanTargetOthers || behavior.CanTargetSelf)
			{
				for (auto&& scenarioTarget : targets)
				{
					if (!behavior.CanTargetOthers && scenarioTarget != this)
					{
						continue;
					}
					if (!behavior.CanTargetSelf && scenarioTarget == this)
					{
						continue;
					}
					auto context = FScenario_Context();
					context.ChosenBehavior = behavior;
					context.Target.SetInterface(scenarioTarget);
					context.Target.SetObject(Cast<UObject>(scenarioTarget));
					context.ThinkingAgent = this;

					scores.ScoredContexts.Add(context);
				}
			}
		}
	}

	//TArray<FScenario_Context> scoredBehaviors;
	//scoredBehaviors.Reserve(scores.ScoredContexts.Num());
	//Algo::Transform(scores.ScoredContexts, scoredBehaviors, [this](auto&& ctx){
	//    const auto rval = NewObject<UScenario_Context>(this);
	//    rval->Initialize(ctx, ctx->ChosenBehavior->Score(broker, ctx));
	//    return rval;});
	//scoredBehaviors.Sort([](auto&& x){return x->score.FinalScore *-1.f /*Decending order desired*/;});

	//if(scoredBehaviors.Num() == 0)
	//{
	//    return TOptional<FScenario_Context>();
	//}

	/*for(auto&& behavior : scoredBehaviors)
    {
        behavior.cxt
    }*/

	//todo: finish implementing
	unimplemented();
	return TOptional<FScenario_Context>();
}
