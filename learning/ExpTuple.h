#pragma once

#include "util/MathUtil.h"

/**
* This is the data structure for the experiment results containing the start state mStateBeg, end state mStateEnd, the action mAction and the reward mReward 
*/

struct tExpTuple
{
public:
	enum eFlag
	{
		eFlagStart,
		eFlagFail,
		eFlagOffPolicy,
		eFlagExpCritic,
		eFlagExpActor,
		eFlagMax
	};

	static bool TestFlag(unsigned int flag, int idx);

	tExpTuple();
	tExpTuple(int state_size, int action_size);

	virtual void ClearFlags();
	virtual void SetFlag(bool val, int idx);
	virtual bool GetFlag(int idx) const;

	int mID;
	double mReward;
	double mActionLogp;
	unsigned int mFlags;
	Eigen::VectorXd mStateBeg;
	Eigen::VectorXd mAction;
	Eigen::VectorXd mStateEnd;
};