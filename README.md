
<!-- README.md is generated from README.Rmd. Please edit that file -->
arrow
=====

The goal of arrow is to have R bindings to [apache arrow](https://arrow.apache.org). This is just a proof of concept right now.

Installation
============

Arrow
-----

[![Travis build status](https://travis-ci.org/jimhester/rarrow.svg?branch=master)](https://travis-ci.org/jimhester/rarrow)
[![AppVeyor build status](https://ci.appveyor.com/api/projects/status/github/jimhester/rarrow?branch=master&svg=true)](https://ci.appveyor.com/project/jimhester/rarrow)

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
# Default print method calls the ToString method on the arrow array
arrow_array(c(1:5, NA, 6:10))
#> [1, 2, 3, 4, 5, null, 6, 7, 8, 9, 10]

# to_r converts the arrow array to an R vector
x <- arrow_array(c(1:5, NA, 6:25))
to_r(x)
#>  [1]  1  2  3  4  5 NA  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22
#> [24] 23 24 25
```
