#pragma once
#include <immintrin.h>

namespace LeakDetector {

	inline Spinlock::Spinlock()
		: mState(Unlocked)
	{
	}

	inline void Spinlock::lock() {
		while (!try_lock()) {
			_mm_pause(); // TODO: intel only
		}
	}

	inline bool Spinlock::try_lock() {
		auto expected = Spinlock::Unlocked;
		return mState.compare_exchange_strong(expected, Spinlock::Locked, std::memory_order_acquire);
	}

	inline void Spinlock::unlock() {
		mState = Spinlock::Unlocked;
	}
}