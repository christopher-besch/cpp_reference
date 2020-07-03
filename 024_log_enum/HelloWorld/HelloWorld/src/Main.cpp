#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Log
{
public:
	enum level : unsigned char
	{
		LevelError = 0, LevelWarning, LevelInfo
	};

private:
	level m_LogLevel = LevelInfo;

public:
	void SetLevel(level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* msg)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]:\t" << msg << std::endl;
	}

	void Warn(const char* msg)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]:\t" << msg << std::endl;
	}

	void Info(const char* msg)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]:\t\t" << msg << std::endl;
	}
};


int main()
{
	Log log;
	log.SetLevel(log.LevelWarning);
	log.Info("Hello!");
	log.Warn("Hello!");
	log.Error("Hello!");

	// the type must be an integer <- float doesn't work
	enum Example : unsigned char
	{
		A, B, C
	};

	Example value = B;

	// value == 1 <- true
	// value == B <- true

	std::cin.get();
}
