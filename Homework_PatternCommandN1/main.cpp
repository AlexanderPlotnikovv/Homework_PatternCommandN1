#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsolePrint : public LogCommand
{
public:
    void print(const std::string& message)
    {
        std::cout << message << std::endl;
    }
};

class FileWriter : public LogCommand
{
public:
    void print(const std::string& message)
    {
        std::ofstream w;
        w.open("File.txt");
        if (w.is_open())
        {
            w << message << std::endl;
        }
        w.close();
    }
};

void print(LogCommand& command, const std::string& message) {
    command.print(message);
}

int main() {
    ConsolePrint con;
    LogCommand* com = new ConsolePrint();

    std::string message = "Hello world!";

    print(*com, message);

    return 0;
}