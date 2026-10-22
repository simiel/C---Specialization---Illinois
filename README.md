# University of Illinois CS 400 — C++ Data Structures

Completed programming assignments from the University of Illinois **CS 400** data-structures coursework, the C++ specialization offered on Coursera (image types are the CS 225 `PNG` / `HSLAPixel` library, updated for CS 400). [Samuel Mensah](https://github.com/simiel) implemented the exercises. University of Illinois course staff supplied the class skeletons, Catch unit tests, Makefiles, and supporting utilities. Each directory is a self-contained assignment you can build and test on its own; the exercise files below are where the algorithms live.

## Assignments

### Hello World

`Hello World/hello-world-given-files` is CS 400 MP 0, also headed Object-Oriented Data Structures in C++, Week 2. `main.cpp` writes `Hello, world!` and `Greetings from Illinois!` to standard output. Course instructions are in `Hello World/hello-world-instructions.pdf`.

### Image transform

`Classes/image-transform-given-files_20190225` processes PNGs in the HSLA color space. LodePNG (`uiuc/lodepng`) handles file I/O. `ImageTransform.cpp` implements:

- **Spotlight** (`createSpotlight`). Lowers each pixel's luminance by 0.5% per pixel of Euclidean distance from a center point, capped at an 80% reduction (distances beyond 160 pixels).
- **Illinify** (`illinify`). Sets every hue to Illini orange (11°) or blue (216°), choosing the nearer color on the 360° hue circle.
- **Watermark** (`watermark`). Where a stencil pixel has luminance 1, raises the base pixel's luminance by 0.2, clamped to 1. The loop covers only the overlapping width and height.

`grayscale` (saturation set to 0) ships with the starter. `main.cpp` reads `alma.png` and `overlay.png` and writes `out-grayscale.png`, `out-spotlight.png`, `out-illinify.png`, and `out-watermark.png`. Instructions: `Classes/image-transform-instructions_20190313.pdf`.

### Linked lists and merge

`Sorting-Lists/LinkedList` is CS 400 MOOC 2, Week 1. The provided `LinkedList<T>` is a doubly linked list: heap nodes, `head_` / `tail_`, `prev` / `next`, and a size kept up to date by each operation. `LinkedListExercises.h` adds the two exercises:

- `insertOrdered` inserts one new node into an already sorted list and leaves every existing node at its current address. It covers an empty list, the front, the middle, and the back.
- `merge` walks two sorted lists once and builds a new sorted list, preserving duplicates. The provided `mergeSortRecursive` and `mergeSortIterative` both call this merge.

Instructions: `Sorting-Lists/LinkedList_project_instructions_20191104a.pdf`.

### Generic trees

`Tree-Traversal` is CS 400 MOOC 2, Week 3. `GenericTree<T>` is an N-ary tree; each node stores its data and a `std::vector` of child pointers. `GenericTreeExercises.h` adds:

- `treeFactory` clears the tree, then builds the assignment's integer tree (root 4, children 8 and 15, and the descendants shown in the file comments).
- `traverseLevels` performs a level-order walk with a `std::queue`, appending node data from left to right and skipping null child pointers. The same template is exercised on `std::string` and `int` trees.

### Hash tables

`Hashmap` is CS 400 MOOC 3, Week 1. `UnorderedMapExercises.cpp` uses `std::unordered_map`:

- `makeWordCounts` maps each distinct string in a vector to the number of times it occurs.
- `lookupWithFallback` reads a const map. When the key is present it returns the mapped `int`; when the key is absent it returns the caller-supplied fallback. The implementation uses `count` and `at`, which keeps the const map unchanged.
- `memoizedLongestPalindromeLength` caches the longest palindromic substring length for each `(left, right)` index pair (`LengthMemo`, an `unordered_map` keyed by `IntPair`). A stored pair returns immediately. The branch that is not itself a palindrome stores the larger of the two recursive results. The function still enforces the course time limit around the recursion.

`main.cpp` runs informal checks, including word counts loaded from `through_the_looking_glass.txt`.

### Graph search

`graph_search` is CS 400 MOOC 3, Week 3. `GraphSearchExercises.cpp` completes four pieces on top of the provided `GridGraph` and `PuzzleState` types:

- `GridGraph::countEdges` counts unique undirected edges. The adjacency map stores each edge at both endpoints, so the neighbor-set sizes are summed and halved.
- `GridGraph::removePoint` deletes a vertex and every edge that touched it. It copies the neighbor set first, then calls `removeEdge` and erases the vertex key.
- `graphBFS` finds a shortest path on a `GridGraph` whose vertices are integer grid points (`IntPair`). Search uses a FIFO queue, a visited set, and predecessor and distance maps, and rebuilds the path from the goal back to the start. It stops at the goal or after 100 steps.
- `puzzleBFS` runs the same search on the implicit graph of the 8-puzzle. A vertex is a `PuzzleState` (eight tiles and a blank on a 3×3 board). Neighbors come from `PuzzleState::getAdjacentStates()`, so only states reached during the search are stored. The search stops after 35 steps, the upper bound the assignment gives for any solvable 8-puzzle.

## Tech stack

- **Language:** C++14 (`-std=c++14`). Makefiles default to `g++` (`CXX_WHICH`; `clang++` is the other compiler named in each makefile).
- **Build:** GNU Make. Object files are written under `.objs/`. Compile flags include `-Wall -Wextra -pedantic -g -O0`; link flags include `-lpthread`.
- **Library:** the C++ standard library (`std::unordered_map`, `std::unordered_set`, `std::queue`, `std::stack`, `std::list`, `std::vector`, `std::array`, `std::chrono`).
- **Tests:** Catch, vendored at `uiuc/catch` (the course Zephyr-style runner, based on Catch2).
- **Images:** LodePNG plus the course `PNG` and `HSLAPixel` classes, used only by the image-transform assignment.

These projects do not read environment variables. There is no root manifest and no shared package install.

## Layout

The six assignments are independent. Course files such as `uiuc/make/uiuc.mk` and `uiuc/catch` are copied into each project.

| Directory | Course unit | Exercise file |
| --- | --- | --- |
| `Hello World/hello-world-given-files` | CS 400 MP 0 | `main.cpp` |
| `Classes/image-transform-given-files_20190225` | CS 400 image transform (CS 225 PNG/HSLA types) | `ImageTransform.cpp` |
| `Sorting-Lists/LinkedList` | CS 400 MOOC 2, Week 1 | `LinkedListExercises.h` |
| `Tree-Traversal` | CS 400 MOOC 2, Week 3 | `GenericTreeExercises.h` |
| `Hashmap` | CS 400 MOOC 3, Week 1 | `UnorderedMapExercises.cpp` |
| `graph_search` | CS 400 MOOC 3, Week 3 | `GraphSearchExercises.cpp` |

`make zip` packs the exercise file named in that makefile. Submission archives already in the tree: `Hashmap/UnorderedMap_submission.zip`, `Tree-Traversal/GenericTree_submission.zip`, and `Classes/image-transform-given-files_20190225/ImageTransform_submission.zip`. Hello World has no `zip` target. Some assignments also have built binaries and `.objs/` checked in; `make clean` removes them.

## Getting started

**Prerequisites:** a C++14 compiler available as `g++`, GNU Make, and `zip` if you regenerate a submission archive. The Hello World tests also invoke `tr`, `sed`, and `grep`.

From the assignment directory:

```bash
make          # demo program: ./main, or ./ImageTransform for the image assignment
make test     # Catch test runner (./test)
./test
make clean    # remove binaries and .objs/ (image transform also removes out-*.png)
```

`make all` builds the demo and the test runner. `make tidy` runs `make clean` and also removes a `doc/` directory.

Image transform writes its PNGs when the demo runs:

```bash
cd "Classes/image-transform-given-files_20190225"
make && ./ImageTransform
```

Linked-list timing cases are tagged `[bench]` and hidden from the default Catch run (see the comments in `tests/week1_tests.cpp`). After `make test`:

```bash
cd Sorting-Lists/LinkedList
./test "[bench]"
```

Quote `[bench]` so the shell does not treat the brackets as a glob. The assignment comments write the same command as `./test [bench]`.

On every assignment except Hello World, `make zip` rebuilds the Coursera submission archive from the exercise file listed in that project's makefile.

## Project status

Coursework. The exercise functions are filled in, and the commits from April through July 2025 record the assignments as completed (the linked-list commit message records that assignment as submitted). The sources are the University of Illinois CS 400 materials headed Spring 2019, with starter version stamps from `20190225` through `20191104a` (`Hello World/hello-world-given-files/version.txt` is `20190722b`). Autograder scores are not recorded in the repository.

## What this demonstrates

- **Pointer-level data structures.** `insertOrdered` allocates a single node and rewires `prev`, `next`, `head_`, and `tail_` so a sorted doubly linked list stays sorted and existing nodes keep their addresses. `merge` is the linear combine step the course mergesort calls.
- **Generic programming.** `LinkedList<T>` and `GenericTree<T>` are class templates. `traverseLevels` is a function template exercised on both `int` and `std::string` trees, using a queue for level order.
- **Hashing as part of the algorithm.** Frequency counting, a const-safe lookup that returns a fallback on a miss, and a memoization table over `(left, right)` index pairs. `IntPair` brings the hash and equality support `unordered_map` needs for that key.
- **Explicit and implicit graphs.** BFS shortest paths on a grid adjacency list (`unordered_map` of neighbor sets), including edge counting that corrects for undirected double storage and vertex deletion that updates both ends of each edge. The 8-puzzle search uses the same predecessor reconstruction on states generated on demand, with the assignment's 35-step bound.
- **Pixel processing.** HSLA edits driven by geometry and color distance: Euclidean luminance falloff, circular hue distance, and a luminance stencil, written back through the course PNG type.
- **Build and test discipline.** Each solution is wired into the course Makefile and Catch suite (`make`, `make test`, `./test`), including the linked-list benchmarks that time `insertOrdered`, `merge`, and the two mergesort implementations.
