#include <arrow/api.h>
#include <arrow/buffer.h>
#include "Rcpp.h"
#include "arrow_types.h"

using namespace arrow;
using namespace Rcpp;

// Buffer for R data, is immutable so we can use the pointer directly.
// Does R's gc compact memory and move objects after allocation? I don't think
// so?
class RBuffer : public Buffer {
 public:
  RBuffer(SEXP data) : Buffer(nullptr, 0) {
    is_mutable_ = false;
    data_ = reinterpret_cast<const uint8_t*>(INTEGER(data));
    size_ = Rf_length(data) * sizeof(int);
    capacity_ = size_;
  }
  ~RBuffer() {}
};

// [[Rcpp::export]]
array_ptr array(IntegerVector input) {
  auto buffer = std::make_shared<RBuffer>(input);

  // The first buffer is the null bitmap, which we are ignoring for now
  BufferVector buffers = {nullptr, buffer};

  auto data = std::make_shared<ArrayData>(int32(), input.length(),
                                          std::move(buffers), 0, 0);
  array_ptr result(new std::shared_ptr<Array>);
  MakeArray(data, &(*result));
  return result;
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
