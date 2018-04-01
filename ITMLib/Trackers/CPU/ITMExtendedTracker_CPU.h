// Copyright 2014-2017 Oxford University Innovation Limited and the authors of InfiniTAM

#pragma once

#include "../Interface/ITMExtendedTracker.h"

namespace ITMLib
{
	class ITMExtendedTracker_CPU : public ITMExtendedTracker
	{
	protected:
		int ComputeGandH_Depth(float &f, float *nabla, float *hessian, Matrix4f approxInvPose);
		int ComputeGandH_RGB(float &f, float *nabla, float *hessian, Matrix4f approxInvPose);
		void ProjectCurrentIntensityFrame(ORFloat4Image *points_out,
										  ORFloatImage *intensity_out,
										  const ORFloatImage *intensity_in,
										  const ORFloatImage *depth_in,
										  const Vector4f &intrinsics_depth,
										  const Vector4f &intrinsics_rgb,
										  const Matrix4f &scenePose);

	public:
		ITMExtendedTracker_CPU(Vector2i imgSize_d,
							   Vector2i imgSize_rgb,
							   bool useDepth,
							   bool useColour,
							   float colourWeight,
							   TrackerIterationType *trackingRegime,
							   int noHierarchyLevels,
							   float terminationThreshold,
							   float failureDetectorThreshold,
							   float viewFrustum_min,
							   float viewFrustum_max,
							   float minColourGradient,
							   float tukeyCutOff,
							   int framesToSkip,
							   int framesToWeight,
							   const ITMLowLevelEngine *lowLevelEngine);
		~ITMExtendedTracker_CPU(void);
	};
}
