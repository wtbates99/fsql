# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/wtb/clones/fsql/build/_deps/csv-src"
  "/home/wtb/clones/fsql/build/_deps/csv-build"
  "/home/wtb/clones/fsql/build/_deps/csv-subbuild/csv-populate-prefix"
  "/home/wtb/clones/fsql/build/_deps/csv-subbuild/csv-populate-prefix/tmp"
  "/home/wtb/clones/fsql/build/_deps/csv-subbuild/csv-populate-prefix/src/csv-populate-stamp"
  "/home/wtb/clones/fsql/build/_deps/csv-subbuild/csv-populate-prefix/src"
  "/home/wtb/clones/fsql/build/_deps/csv-subbuild/csv-populate-prefix/src/csv-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/wtb/clones/fsql/build/_deps/csv-subbuild/csv-populate-prefix/src/csv-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/wtb/clones/fsql/build/_deps/csv-subbuild/csv-populate-prefix/src/csv-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
