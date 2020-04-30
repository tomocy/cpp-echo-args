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
}  // namespace echoargs

#endif