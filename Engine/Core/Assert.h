#pragma once

#ifdef NDEBUG
//release version

#define ASSERT(condition) ((void)0)
#define ASSERT_MSG(condition, message) ((void)0)


#else
//debug version
#define ASSERT(condition) Assert((condition), #condition, __FILE__, (unsigned)(__LINE__), __func__)
#define ASSERT_MSG(condition, message) Assert((condition), #condition, __FILE__, (unsigned)(__LINE__), __func__, message)



#endif

void Assert
(
	bool condition,
	const std::string& conditionString,
	const std::string& fileName,
	int line,
	const std::string& funcName,
	const std::string message = ""
);