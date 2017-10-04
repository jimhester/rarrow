#include <arrow/api.h>
#include "Rcpp.h"
#include "arrow_types.h"

using namespace arrow;
using namespace Rcpp;

// [[Rcpp::export]]
array_ptr array() {
  Int32Builder builder;
  builder.Append(1);
  builder.Append(2);
  builder.Append(3);
  array_ptr array(new std::shared_ptr<arrow::Array>);
  builder.Finish(&(*array));
  return array;
}

// [[Rcpp::export]]
CharacterVector array_string(array_ptr const& array) {
  return (*array)->ToString();
}

// [[Rcpp::export]]
IntegerVector as_r_int(array_ptr const& array) {
  std::shared_ptr<Int32Array> int32_array =
      std::static_pointer_cast<Int32Array>(*array);

  int n = (*array)->length();

  IntegerVector out(n);
  memcpy(INTEGER(out), int32_array->raw_values(), n * sizeof(int));

  return out;
}
