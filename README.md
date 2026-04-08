*This project has been created as part of the 42 curriculum by sarzuman, <login2>.*

# push_swap (learner base + completion)

## Description

Sort stack `a` using only the allowed operations. This tree keeps the original design: **doubly linked list** for stacks, operations split across `swap.c`, `push.c`, `rotate.c`, `revers_rotate.c`, plus parsing and validation in `errors.c` / `parse.c`.

Embedded strategies (subject v1.1):

| Flag | Idea |
|------|------|
| `--simple` | Selection-style minimum extraction — `O(n^2)` |
| `--medium` | Chunk / `sqrt(n)` range pass — `O(n*sqrt(n))` |
| `--complex` | Radix (LSD) on ranks — `O(n*log n)` |
| `--adaptive` | Disorder-based thresholds (default) |

`--bench` prints metrics to **stderr** after sorting.

## Instructions

```bash
make
make bonus    # builds checker
```

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
./checker <integers...>   # then type operations on stdin, EOF to finish
```

Example:

```bash
./push_swap --complex 4 67 3 87 23 | ./checker 4 67 3 87 23
```

## Algorithms (brief)

- **Disorder**: inversion ratio over all pairs (before any move).
- **Adaptive**: `<0.2` → simple; `0.2–0.5` → medium; `≥0.5` → complex.
- **Ranks**: before medium/complex, values are replaced by ranks `0..n-1` for stable chunk/radix passes.

## Resources

- Subject PDF (push_swap v1.1)
- Knuth / standard references on radix sort and inversion counts

### AI usage

AI was used to wire `main`, parsing, strategies, `bench`, and `checker` on top of the learner’s list and operation code; review and own every line before evaluation.

## Contribution

- \<login1\>: list nodes, stack moves (`swap` / `push` / `rotate`), `ft_strcmp`, `errors`.
- \<login2\>: `parse`, strategies, `bench`, `checker`, integration.
