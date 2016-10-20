#pragma once
#include"../stdafx.hpp"

namespace XUI 
{

	class SIMPLEDIRECTUI_API AnimationInterpolator 
	{
	public:
		virtual double calculate(unsigned long total, unsigned long process) = 0;
	};

	class SIMPLEDIRECTUI_API LinearInterpolator : public AnimationInterpolator
	{
	public:
		static std::shared_ptr<LinearInterpolator> linearInterpolator() {
			return std::make_shared<LinearInterpolator>();
		}
		virtual double calculate(unsigned long total, unsigned long process) override {
			return process / (double)total;
		}
	};

	class SIMPLEDIRECTUI_API TestInterpolator : public AnimationInterpolator {
	public:
		virtual double calculate(unsigned long total, unsigned long x) override {
			double y = (double)x / (double)total * 100.0;
			return (-0.012244897959183789*y*y+2.2367346938775574*y-1.2244897959183738)/100.0;
		}
	};

	enum class AnimatingStates {
		Stopped,
		Playing,
		Paused,
	};

	class SIMPLEDIRECTUI_API Animation
	{
	public:
		Animation() {
			mInterpolator = Animation::mDefaultInterpolator;
		}
		virtual ~Animation();
		virtual bool setProcessFun(const std::function<void(double)> &fun);
		Animation& setAutoRemove(bool autoRemove = true);
		Animation& setAnimationInterpolator(std::shared_ptr<AnimationInterpolator> interpolator);
		Animation& setDurationMS(unsigned long ms);
		Animation& setRepeatTimes(long times);
		virtual bool play();
		virtual void pause();
		virtual void stop();
		void process(unsigned long ms);
		AnimatingStates state();

		void removeFromSystem(){}
		std::function<void(void)> onFinish;
		std::function<void(void)> onStart;
		std::function<void(void)> onStop;
	protected:
		std::function<void(double)> mProcessFun;
		unsigned long mProcessedMs = 0;
		unsigned long mRepeatedTimes = 0;

		bool mIsAutoRemove = false;
		long mRepeatTimes = 0;
		unsigned long mDurationMS = 400;
		AnimatingStates mState = AnimatingStates::Stopped;
		std::shared_ptr<AnimationInterpolator> mInterpolator;
	private:
		static std::shared_ptr<AnimationInterpolator> mDefaultInterpolator;
	};

	template <typename T>
	class ValueAnimation : public Animation {
	public:
		static std::shared_ptr<ValueAnimation<T>> createAni(T startValue, T endValue, const std::function<void(T)> &fun) {
			return std::make_shared<ValueAnimation<T>>(startValue, endValue, fun);
		}
		ValueAnimation(T startValue, T endValue, const std::function<void(T)> &fun) {
			mStartValue = startValue;
			mEndValue = endValue;
			mChangeValue = endValue - startValue;
			mProcessFun = std::bind(&ValueAnimation<T>::_processFun, this, std::placeholders::_1);
			mProcessValueFun = fun;
		}
		virtual bool setProcessFun(const std::function<void(double)> &fun) override {
			return false;
		}
		void setProcessValueFun(const std::function<void(T)> &fun) {
			mProcessValueFun = fun;
		}
	private:
		void _processFun(double p) {
			mProcessValueFun(mStartValue + mChangeValue * p);
		}
		std::function<void(T)> mProcessValueFun;
		T mStartValue;
		T mChangeValue;
		T mEndValue;
	};

}