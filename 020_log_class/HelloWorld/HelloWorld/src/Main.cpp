#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo;

public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Error(const char* msg)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]:\t" << msg << std::endl;
	}

	void Warn(const char* msg)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]:\t" << msg << std::endl;
	}

	void Info(const char* msg)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]:\t\t" << msg << std::endl;
	}
};


int main()
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Info("Hello!");
	log.Warn("Hello!");
	log.Error("Hello!");

	std::cin.get();
}
