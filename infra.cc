#include "infra.h"

#include <iostream>

#include "echoargs.h"

echoargs::EchoStatus infra::console::Echoer::Echo(
    const echoargs::Args& args) const {
  auto vs = args.Values();
  int size = vs.size();
  for (auto i = 0; i < size; ++i) {
    std::cout << vs.at(i);
    if (i != size - 1) {
      std::cout << ", ";
    }
  }

  std::cout << std::endl;

  return echoargs::EchoStatus::SUCCESS;
}