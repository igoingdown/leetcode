# LeetCode Practice Repository - Architecture Overview

## Project Overview

This repository is a comprehensive collection of LeetCode problem solutions and algorithm implementations, primarily focused on competitive programming and technical interview preparation. The codebase contains solutions to 800+ LeetCode problems across various difficulty levels, organized by problem number and algorithmic approach.

**Architecture Pattern**: Monolithic structure with modular organization by:
- Problem-specific implementations (e.g., `10.cpp`, `101.cpp`)
- Algorithmic technique groupings (e.g., `*_bfs.cpp`, `*_dp.cpp`, `*_recursion.cpp`)
- Domain-specific collections (interviews, books, testing)

**Primary Languages**: C++ (95%), Java (3%), Python (2%)

## Build & Commands

### Compilation Commands
```bash
# Individual problem compilation
g++ -std=c++17 -O2 -Wall -o problem_name problem_name.cpp

# Directory-specific builds (using provided Makefiles)
cd the_cherno/001-test-file-static && make
cd test_asm && make
cd interviews/001-quant/001-kaidutouzi && make

# Clean builds
make clean
```

### Development Workflow
1. **Problem Selection**: Navigate to specific problem file (e.g., `104_BFS.cpp`)
2. **Testing**: Use provided test files in subdirectories
3. **Compilation**: Use standard g++ with C++17 features
4. **Execution**: Run compiled binaries directly

### Testing Commands
```bash
# Run individual test
g++ -std=c++17 test_file.cpp && ./a.out

# Test specific algorithm implementations
cd sort_algorithms && g++ -std=c++17 quick_sort.cpp && ./a.out
```

## Code Style

### Naming Conventions
- **Files**: `problem_number[_algorithm].cpp` (e.g., `104_BFS.cpp`, `104_DFS.cpp`)
- **Variables**: snake_case for C++, camelCase for Java
- **Functions**: descriptive names indicating algorithm (e.g., `maxDepth_DFS`, `longestPalindrome_DP`)
- **Classes**: PascalCase (e.g., `Solution`, `TreeNode`)

### Formatting Standards
- **Indentation**: 2 spaces for C++, 4 spaces for Python
- **Braces**: Opening brace on same line for C++
- **Comments**: Chinese for problem insights, English for code documentation
- **Headers**: Standard library includes grouped together

### Best Practices
- Multiple solution approaches for single problems (e.g., `*_bfs.cpp`, `*_dfs.cpp`, `*_dp.cpp`)
- Performance annotations in filenames (e.g., `*_tle.cpp` for time limit exceeded)
- Memory optimization indicators (e.g., `*_mle.cpp` for memory limit exceeded)

## Testing

### Framework
- **Primary**: Custom test cases within each file
- **Secondary**: Provided test files in subdirectories
- **Validation**: LeetCode online judge compatibility

### Test Structure
```
test_*/
├── test.cpp          # Main test file
├── test              # Compiled binary
├── graph.txt         # Test data
└── README.md         # Test instructions
```

### Testing Guidelines
- Include edge cases in problem-specific implementations
- Use provided test directories for algorithm validation
- Document time/space complexity in comments
- Test multiple approaches for comparison

## Security

### Data Protection
- **No sensitive data**: Repository contains only algorithmic solutions
- **Public information**: All problems are from public LeetCode platform
- **Clean commits**: No API keys or personal information

### Code Security
- **Input validation**: All solutions handle edge cases (empty inputs, boundary values)
- **Memory safety**: Proper cleanup in C++ implementations
- **Integer overflow**: Explicit handling in numerical problems

## Configuration

### Environment Setup
```bash
# Required tools
g++ (GCC) 7.0+ with C++17 support
Java 8+ (for .java files)
Python 3.6+ (for .py files)
make utility

# Optional tools
Valgrind for memory debugging
GDB for debugging
```

### Directory Structure
```
leetcode/
├── *.cpp              # Individual problem solutions
├── notes/             # Algorithm documentation
├── books/             # Algorithm book implementations
├── interviews/        # Interview preparation problems
├── sort_algorithms/   # Sorting implementations
├── test_*/            # Testing subdirectories
├── the_cherno/        # C++ feature testing
└── tree_traversal/    # Tree algorithm implementations
```

### Build Configuration
- **Standard**: C++17 across all C++ files
- **Warnings**: -Wall flag enabled
- **Optimization**: -O2 for production builds
- **Debug**: Debug builds use -g flag

## Quick Start

1. **Clone repository**
2. **Navigate to problem**: `cd leetcode && ls 100.cpp`
3. **Compile**: `g++ -std=c++17 -O2 100.cpp`
4. **Run**: `./a.out`
5. **Test alternatives**: Compare `*_bfs.cpp` vs `*_dfs.cpp` approaches

## Key Algorithm Categories

- **Graph**: BFS, DFS, Dijkstra, Union-Find
- **Dynamic Programming**: 1D/2D DP, state machines
- **Trees**: Traversal, LCA, BST operations
- **Sorting**: All major algorithms with implementations
- **String**: KMP, Trie, sliding window
- **Math**: Number theory, combinatorics

## Performance Indicators

File suffixes indicate performance characteristics:
- `*_tle.cpp`: Time Limit Exceeded (for learning purposes)
- `*_mle.cpp`: Memory Limit Exceeded
- `*_wa.cpp`: Wrong Answer (debugging versions)
- `*_ac.cpp`: Accepted solution
- `*_optimized.cpp`: Performance optimized version