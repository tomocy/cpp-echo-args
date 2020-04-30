#ifndef INFRA_H
#define INFRA

#include "echoargs.h"

namespace infra::console {
class Echoer : public echoargs::Echoer {
 public:
  echoargs::EchoStatus Echo(const echoargs::Args&) const override;
};
}  // namespace infra::console

#endif