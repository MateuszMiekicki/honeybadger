#!/bin/bash
cd build
mkdir -p gcov_reports
cd gcov_reports
find ../test/CMakeFiles/honeybadger_test.dir/coverage -name '*.*.gcno' -exec gcov "{}" \;