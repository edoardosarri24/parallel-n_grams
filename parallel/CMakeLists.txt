project(parallel_trigrams C)
add_executable(parallel_trigrams)

# sources
target_sources(parallel_trigrams PRIVATE
    src/main.c
    src/hash_table.c
    src/arena.c
    src/main_functions.c
    src/statistics.c
    src/my_utils.c
)

# includes
target_include_directories(parallel_trigrams PRIVATE
    include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

# libraries
target_link_libraries(parallel_trigrams PRIVATE OpenMP::OpenMP_C)

# hyperparameters
target_compile_definitions(parallel_trigrams PRIVATE
    DATA_DIR=\"${CMAKE_SOURCE_DIR}/data\"
    N_GRAM_SIZE=${N_GRAM_SIZE}
    TOP_K=${TOP_K}
)