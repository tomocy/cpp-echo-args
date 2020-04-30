#include "echoargs.h"

#include <string>
#include <vector>

echoargs::Args::Args(const std::vector<std::string>& vals) : vals(vals) {}

std::vector<std::string> echoargs::Args::Values() const { return vals; }