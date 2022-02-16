#!/bin/bash
lcov --capture --directory build/src --output-file build/Testing/coverage.info --rc lcov_branch_coverage=1
lcov --remove build/Testing/coverage.info '/usr/*' --output-file build/Testing/coverage.info --rc lcov_branch_coverage=1 # filter system-files