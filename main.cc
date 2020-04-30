
#include <iostream>
#include <string>
#include <vector>

#include "echoargs.h"
#include "infra.h"

const std::string kEnvEchoer = "ECHOER";
const std::string kEchoerConsole = "console";

enum class Echoer {
  CONSOLE,
};

Echoer MapEchoer(const std::string& e) {
  if (e == "tomocy") {
    printf("tomocy!\n");
  }

  return Echoer::CONSOLE;
}

Echoer MapEchoer(const char* e) {
  auto kind = kEchoerConsole;
  if (e != nullptr) {
    kind = std::string(e);
  }

  return MapEchoer(kind);
}

echoargs::EchoStatus Echo(const echoargs::Echoer& e,
                          const echoargs::Args& args) {
  return e.Echo(args);
}

echoargs::EchoStatus Echo(const Echoer& e, const echoargs::Args& args) {
  echoargs::EchoStatus status;
  switch (e) {
    default:
      status = Echo(infra::console::Echoer(), args);
  }

  return status;
}

echoargs::Args ParseArgs(int n, char* const args[]) {
  auto size = n - 1;
  auto vs = std::vector<std::string>(size);
  for (auto i = 0; i < size; ++i) {
    vs.at(i) = args[i + 1];
  }

  return echoargs::Args(vs);
}

int main(int n, char* args[]) {
  auto e = MapEchoer(getenv(kEnvEchoer.c_str()));
  auto parsed = ParseArgs(n, args);

  auto status = Echo(e, parsed);

  return status == echoargs::EchoStatus::SUCCESS ? 0 : 1;
}