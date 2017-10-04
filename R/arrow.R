#' @useDynLib arrow, .registration = TRUE
#' @importFrom Rcpp sourceCpp
NULL

arrow_array <- function() {
  structure(list(ptr = array()), class = "arrow_array")
}

#' @export
print.arrow_array <- function(x, ...) {
  cat(array_string(x$ptr))
}

#' @export
to_r <- function(x) {
  as_r_int(x$ptr)
}
