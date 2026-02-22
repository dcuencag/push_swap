# Push_swap

A C program that sorts a stack of integers using a limited set of operations, outputting the shortest possible sequence of moves.

This project is part of the 42 school curriculum and focuses on algorithmic efficiency and complexity.

## The Problem

Given a stack `a` of unsorted integers and an empty stack `b`, sort all numbers in ascending order in `a` using only the allowed operations, with as few moves as possible.

## Allowed Operations

| Operation | Description |
|---|---|
| `sa` | Swap the top two elements of stack `a` |
| `sb` | Swap the top two elements of stack `b` |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of `b` onto `a` |
| `pb` | Push the top of `a` onto `b` |
| `ra` | Rotate `a` upward (top becomes bottom) |
| `rb` | Rotate `b` upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate `a` (bottom becomes top) |
| `rrb` | Reverse rotate `b` |
| `rrr` | `rra` and `rrb` simultaneously |

## Usage

```bash
make
./push_swap 3 2 1 5 4
```

Arguments can also be passed as a single quoted string:

```bash
./push_swap "3 2 1 5 4"
```

The program prints the list of operations to stdout, one per line.

### Checking the result

```bash
./push_swap 3 2 1 5 4 | ./checker_Mac 3 2 1 5 4
# OK
```

## Algorithm

- **2 elements**: single `sa`.
- **3 elements**: hardcoded optimal sequence (`sort_three`).
- **4+ elements**: greedy **Turkish sort** (cost-based):
  1. Push all but 3 elements from `a` to `b`, always choosing the node with the lowest combined rotation cost (rotations needed in `a` + rotations needed in `b` to reach its target position).
  2. Sort the remaining 3 elements in `a` with `sort_three`.
  3. Push elements back from `b` to `a` one by one, each time rotating `a` so the target slot is on top.
  4. Rotate `a` until the minimum is on top.

Each node tracks its **push cost** (`above_median` flag + index distance) so the cheapest move is always selected.

## Build

```bash
make        # build push_swap and libft
make clean  # remove object files
make fclean # remove object files and binary
make re     # full rebuild
```

## File Structure

| File | Description |
|---|---|
| `main.c` | Entry point, input handling, algorithm dispatch |
| `stack_init.c` | Initialize stack `a`, find cheapest node, prep rotations |
| `stack_utils.c` | `stack_len`, `find_min/max`, `stack_sorted`, all operations |
| `init_a_to_b.c` | Cost analysis for pushing from `a` to `b` |
| `init_b_to_a.c` | Target resolution for pushing from `b` to `a` |
| `error.c` | Syntax/duplicate validation, memory cleanup |
| `mutable_split.c` | String split for single-argument input |
| `operations/swap.c` | `sa`, `sb`, `ss` |
| `operations/push.c` | `pa`, `pb` |
| `operations/rotate.c` | `ra`, `rb`, `rr` |
| `operations/rev_rotate.c` | `rra`, `rrb`, `rrr` |
| `operations/sort_three.c` | Optimal 3-element sort |
| `operations/sort_stacks.c` | Main sorting algorithm |
| `operations/sort_stacks_utils.c` | Move helpers for `a→b` and `b→a` |
| `libft/` | Custom C standard library |

## Author

dancuenc — 42 Madrid
