
<!-- README.md is generated from README.Rmd. Please edit that file -->
arrow
=====

The goal of arrow is to have R bindings to [apache arrow](https://arrow.apache.org). This is just a proof of concept right now.

Installation
============

Arrow
-----

First install a release build of the C++ bindings to arrow.

``` shell
git clone https://github.com/apache/arrow.git
cd arrow/cpp && mkdir release && cd release

# It is important to statically link to boost libraries
cmake .. -DCMAKE_BUILD_TYPE=Release -DARROW_BOOST_USE_SHARED:BOOL=Off
make install
```

Example
-------

``` r
library(arrow)
x <- arrow_array()
# Default print method calls the ToString method on the arrow array
x
#> [1, 2, 3]

# to_r converts the arrow arrow to an R vector
to_r(x)
#> [1] 1 2 3
```
