#include "Behavior.h"
#include "Curvature.h"
#include "Interfaces/InputBrokerInterface.h"
#include "Scenarios/Scenario_Context.h"

FString FBehavior::ToString() const
{
	return ReadableName != NAME_None ? ReadableName.ToString() : FString(TEXT("(Untitled)"));
}

FScenario_ConsiderationScores FBehavior::Score(IInputBrokerInterface* broker, const FScenario_Context& context)
{
	auto ret = FScenario_ConsiderationScores();
	const auto compensationFactor = 1.f - (1.f / static_cast<float>(Considerations.Num()));
	auto result = Weight;
	ret.InitialWeight = Weight;

	for (auto&& c : Considerations)
	{
		auto considerationScore = c.Score(*broker, context);
		const auto modification = (1.f - considerationScore.FinalScore) * compensationFactor;
		considerationScore.FinalScore = considerationScore.FinalScore + (modification * considerationScore.FinalScore);
		result *= considerationScore.FinalScore;
		//ret.Considerations.Add(c, considerationScore);
	}

	ret.FinalScore = result;
	return ret;
}
