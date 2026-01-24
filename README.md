# parallel-trigrams

### Requirements
- CMake
- The [GPerfTools](https://developer.ridgerun.com/wiki/index.php/Profiling_with_GPerfTools).
- The modern Go version of [pprof](https://github.com/google/pprof)
- OpenMP

### Installation
- Set your pprof path in [profiling.sh](exec/profiling.sh) executable.

### Execution
Use the scripts in the `exec/` directory to build and run the project. All scripts require a mandatory argument: `seq` or `par`.
- **Run:** `./exec/execution.sh [seq|par]` - Builds and runs the application.
- **Profile:** `./exec/profiling.sh [seq|par]` - Builds with profiling enabled, runs, and generates reports in `[sequential|parallel]/result_profiling/`.
- **Sanitizers:**
  - `./exec/AUBsanitizer.sh [seq|par]` - Runs with Address and Undefined Behavior Sanitizers.
  - `./exec/Msanitizer.sh [seq|par]` - Runs with Memory Sanitizer.