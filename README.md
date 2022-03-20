# Honeybadger

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FMateuszMiekicki%2Focr.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FMateuszMiekicki%2Focr?ref=badge_shield)
[![CircleCI](https://circleci.com/gh/MateuszMiekicki/honeybadger/tree/master.svg?style=svg)](https://circleci.com/gh/MateuszMiekicki/honeybadger/tree/master)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=MateuszMiekicki_honeybadger&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=MateuszMiekicki_honeybadger)
[![Coverage Status](https://coveralls.io/repos/github/MateuszMiekicki/honeybadger/badge.svg?branch=master)](https://coveralls.io/github/MateuszMiekicki/honeybadger?branch=master)

## Important files

1. [License](LICENSE)
2. [Security](SECURITY.md)
3. For Contributors
    1. [pull request](docs/contributing_template/pull_request.md)
    2. [bug](docs/contributing_template/bug.md)
    3. [feature](docs/contributing_template/feature.md)
    4. [ADR](docs/architecture_decision_record/README.md)
4. [Changelog](CHANGELOG.md)
5. [Vision]()
6. [Code Of Conduct](CODE_OF_CONDUCT.md)

## Build

```bash
git clone https://github.com/MateuszMiekicki/honeybadger.git
cd honeybadger
cmake -Bbuild -G Ninja -DCMAKE_BUILD_TYPE=Relese 
cmake --build build --target INSTALL
cd config/
```

## Usage

In principle, there are three methods of knowing how to act. Documentation, examples and tests.

## Branch nomenclature

I do not stick to branchy. Everything will be attached to the master. On a continuous delivery basis. The only two types
that come to mind and I can see a use for them.

1. **fix** Bug fix
2. **feature** Throwaway branch created to experiment

## License

[BSD Zero Clause License](https://choosealicense.com/licenses/0bsd/)

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FMateuszMiekicki%2Focr.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2FMateuszMiekicki%2Focr?ref=badge_large)
