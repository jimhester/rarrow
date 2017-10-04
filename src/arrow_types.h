#pragma once

#include <arrow/api.h>
#include "Rcpp.h"

typedef Rcpp::XPtr<std::shared_ptr<arrow::Array>> array_ptr;
