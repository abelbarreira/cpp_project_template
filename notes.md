# Notes

- **Clang-Tidy**:
  - [Formatter and Static Analyzer](README_install.md)
  - Clang-Tidy: **Static Linting** tool for your C/C++ code
  - Clang-Tidy linter just checks the code regarding some predefined checks
  - Linting allows to finds bugs in our code earlier on, before to compile
  - It is not needed to use the CLang compiler for it, even it is in the name
  - `clang-tidy --version`, use, at least, `Ubuntu LLVM version 14.0.0`
  - [.clang-tidy](.clang-tidy):
    - Which is the configuration file where are listed which checks/warnings are activated/deactivated
  - [Tools.cmake](cmake/Tools.cmake):
    - Where function `add_clang_tidy_to_target` is defined and it uses
      - `.clang-tidy`
      - `run-clang-tidy.py`
    - `add_custom_target`:
      - A custom target is not a standard CMake target where we want to compile something or call the compiler, it is just for defining a utility target where we can just execute something in the console
    - [Link](https://clang.llvm.org/extra/clang-tidy/) to find out what can be activated
    - Set `CMAKE_EXPORT_COMPILE_COMMANDS` to `ON`. This will generate `build/compile_commands.json` that has to be created, otherwise Clang-Tidy doesn't know where to look or which files belongs to our code, because Clang-Tidy is run before compilation
