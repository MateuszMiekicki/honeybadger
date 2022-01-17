#!/bin/bash
<<<<<<< HEAD
cd build || exit
mkdir -p gcov_reports
cd gcov_reports || exit
find ../test/CMakeFiles/honeybadger_test.dir/image/preprocessing -name '*.*.gcno' -exec gcov -b -l -p -c "{}" \;
find ../test/CMakeFiles/honeybadger_test.dir/image/preprocessing -name '*.*.gcno' -exec echo "{}" \;
=======
cd build
mkdir -p gcov_reports
cd gcov_reports
find ../test/CMakeFiles/honeybadger_test.dir/coverage -name '*.*.gcno' -exec gcov "{}" \;
>>>>>>> ci_test
