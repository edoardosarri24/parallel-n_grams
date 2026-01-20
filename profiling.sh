cmake -S . -B build -DENABLE_SANITIZER=OFF -DENABLE_PROFILING=ON
cmake --build build
CPUPROFILE=whole.prof ./build/sequential/sequential_trigrams
# Using the Go-based pprof installed via asdf
/Users/edoardosarri/.asdf/installs/golang/1.25.6/bin/pprof --text ./build/sequential/sequential_trigrams whole.prof > sequential/result_profiling/profile.txt
/Users/edoardosarri/.asdf/installs/golang/1.25.6/bin/pprof --pdf ./build/sequential/sequential_trigrams whole.prof > sequential/result_profiling/profile.pdf
rm whole.prof