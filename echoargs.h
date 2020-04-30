#ifndef ECHOARGS_H
#define ECHOARGS_H

#include <string>
#include <vector>

namespace echoargs {
class Args {
 public:
  Args(const std::vector<std::string>&);
  std::vector<std::string> Values() const;

 private:
  std::vector<std::string> vals;
};

enum class EchoStatus {
  SUCCESS,
  FAILURE,
};

class Echoer {
 public:
  virtual ~Echoer() {}
  virtual EchoStatus Echo(const Args&) const = 0;
};
}  // namespace echoargs

#endif