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
  - The deployment can be seen in [github-pages deployments](https://github.com/abelbarreira/cpp_project_template/deployments/github-pages) in the link [github.io: cpp_project_template](https://abelbarreira.github.io/cpp_project_template/)
  - Trying to disabling the rest of the workflows and only keep the `documentation.yml`

- **Unit Test Updates**

- **Code Coverage**:
  - It can only be compute the code coverage on Linux or on MAC
  - [Coverage Tools Install](README_install.md):
    - `sudo apt-get install gcovr`
  - `gcovr --version`
  - Use the flag `ENABLE_COVERAGE`
  - Reports are generated in `./build/coverage`

- **GitHub Actions**:
  - [Understanding GitHub Actions](https://docs.github.com/en/actions/about-github-actions/understanding-github-actions):
    - A **workflow** is a configurable automated process that will run one or more **jobs**.
      - Workflows are defined by a **YAML** file checked in to your repository and will run when triggered by an event in your repository, or they can be triggered manually, or at a defined schedule
      - Workflows are defined in the `.github/workflows` directory in a repository
        - You can reference a workflow within another workflow.
    - An **event** is a specific activity in a repository that triggers a workflow run:
      - For example:
        - Create a pull request
        - Open an issue, or
        - Push a commit to a repository
      - You can also trigger a workflow to run on a **schedule** or **manually**.
    - A **job** is a set of steps in a workflow that is executed on the same runner.
      - Each step is:
        - A **shell script** that will be executed, or
        - An **action** that will be run
      - Steps are executed in order and are dependent on each other
      - Since each step is executed on the same runner, you can share data from one step to another
      - You can configure a job's dependencies with other jobs
      - By default, jobs have no dependencies and run in parallel
      - When a job takes a dependency on another job, it waits for the dependent job to complete before running
    - An **action** is a custom application for the **GitHub Actions platform** that performs a complex but frequently repeated task
      - Use an action to help reduce the amount of repetitive code that you write in your workflow files
    - A **runner** is a server that runs your workflows when they're triggered:
      - Each runner can run a single job at a time
      - Each workflow run executes in a fresh, newly-provisioned virtual machine
    - [Creating an Example Workflow](https://docs.github.com/en/actions/use-cases-and-examples/creating-an-example-workflow)
    - [GitHub Actions](https://github.com/actions) for automate your GitHub workflows
    - [Disable/Enabling workflows](https://docs.github.com/en/actions/managing-workflow-runs-and-deployments/managing-workflow-runs/disabling-and-enabling-a-workflow?tool=webui)

- **GitHub Pull Requests**:
  - [Git Pull Request](https://www.geeksforgeeks.org/git-pull-request/)
  - In GitLab is called Merge Request

- **GitHub Actions** for Unit Testing and Code Coverage:
  - Following workflows:
    - [MAC OS](.github/workflows/macos.yml)
    - [Ubuntu](.github/workflows/ubuntu.yml)
    - [Windows](.github/workflows/windows.yml)

- **Pre-Commit**:
  - Using the tool of `pre-commit` is possible to force to others to do CLang o CMake Formats
  - `pip install pre-commit` -> `pre-commit 4.2.0` after `source ~/.profile`
  - `sudo apt install pre-commit` -> `pre-commit 2.17.0`
  - Then we have to setup the pre-commit in our repository using `.pre-commit-config.yam`
    - Those checks will be run whenever we do a commit
  - For this we have to use
    - `pre-commit install`, and
    - `pre-commit install-hooks`
  - And then do a commit that is doing the checks before to commit them
  - In case they don't want to install the pre-commit tool on their side, then we can use `.github/workflows/pre-commit.yml`

- **Install Command**:
  - About how we can install our Executable or our Library in the computer as any other tool
  - It is using `install()` command in `CMakeLists.txt`
  - It will be created an `install` target
  - It has to be run with admin rights with `sudo cmake --build . --target install`:
        ```sh
        Install the project...
        -- Install configuration: "Debug"
        -- Installing: /usr/local/bin/main
        -- Installing: /usr/local/lib/libLibFoo.a
        -- Installing: /usr/local/lib/libLibBar.a
        ```
  - Then it is possible to run `main`

- **CMake Extension: Debugging and Running**:
  - In case we need to pass arguments to the module to debug, we can use `.vscode/settings.json` in `cmake.debugConfig`
  - Also possible to use VSCode tasks for it
