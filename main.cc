
#include <string>
#include <valarray>
#include <vector>

#include "echoargs.h"
#include "infra.h"

echoargs::EchoStatus Echo(const echoargs::Echoer& e,
                          const echoargs::Args& args) {
  return e.Echo(args);
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
  auto e = infra::console::Echoer();
  auto parsed = ParseArgs(n, args);
  auto status = Echo(e, parsed);

  return status == echoargs::EchoStatus::SUCCESS ? 0 : 1;
}