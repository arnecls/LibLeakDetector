#pragma once

#include <atomic>

namespace LeakDetector {

	class Spinlock {
	private:
		std::atomic_int32_t mState;

		static const int32_t Unlocked = 0;
		static const int32_t Locked = 1;

	public:

		inline Spinlock();

		inline void lock();
		inline bool try_lock();
		inline void unlock();
	};
}

#include "spinlock.hpp"