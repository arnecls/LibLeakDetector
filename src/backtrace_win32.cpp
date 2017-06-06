#ifdef _WIN32

#include "backtrace.h"
#include "windows_sane.h"

namespace LeakDetector {

	void Backtrace(std::vector<void*>& aFrames, size_t aSkip, size_t aNumFrames) {
		if (aNumFrames == 0 && aFrames.capacity() < aNumFrames) {
			aFrames.reserve(aNumFrames);
		}
		aFrames.resize(aFrames.capacity());
		void** pBuffer = &aFrames[0];

		auto numFrames = CaptureStackBackTrace(aSkip+1, aFrames.capacity(), pBuffer, nullptr);
		aFrames.resize(numFrames);
	}
}

#endif