# Notes

- [cpp_project_template](https://github.com/abelbarreira/cpp_project_template)

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

- **Clang-Format**:
  - It is a formatting tool for C/C++, to be used in any operating system
  - Again, not need to use the Clang Compiler for it
  - `clang-format --version`, at least version 14.0, since `tools/run-clang-format.py` expect it
  - It is using following format configuration `.clang-format`
  - It is activated with `ENABLE_CLANG_FORMAT`
  - Using function `add_clang_format_target` in `cmake/Tools.cmake`

- **Cmake-Format**:
  - This is to format `.cmake` files
  - `pip install cmake-format # python 3.7+`
  - `source ~/.profile`, adding to the path
  - It is using following format configuration `.cmake-format.yaml`
  - It is activated with `ENABLE_CMAKE_FORMAT`
  - Using function `add_cmake_format_target` in `cmake/Tools.cmake`

- **GitHub Pages**:
  - Once generated the Doxygen documentation in `docs/html` using the `docs` cmake target
  - This folder can be updated to GitHub pages, in the `gh-pages` branch, and it will be as web host for this information
  - For this, in the repository in GitHub we have to go to `Settings->Pages->Activated` and indicate to use `gh-pages` branch
    - [Settings->Pages](https://github.com/abelbarreira/cpp_project_template/settings/pages)
  - Then there is `.github/workflows/documentation.yml` which is executed whenever is created a new tag, as a new version or whenever we push in the main or master branch.
  - It is needed to configure `Read and write permissions` in [Settings->Actions](https://github.com/abelbarreira/cpp_project_template/settings/actions)
