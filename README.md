# get_next_line

Read a file descriptor line by line — one call at a time.

---

## Usage

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

Returns the next line (including `\n`) on each call. Returns `NULL` when done or on error.

---

## How It Works

Uses a `static` remainder buffer to persist leftover data between calls:

1. Read `BUFFER_SIZE` bytes into a buffer
2. Append to remainder
3. Once `\n` is found — extract the line
4. Keep what's left for the next call

---

## Custom BUFFER_SIZE

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Default is `100` if not specified.

---

## Files

| File | Description |
|---|---|
| `get_next_line.c` | Core logic |
| `get_next_line_utils.c` | Helper functions (`strlen`, `strchr`, `substr`, `memcpy`) |
| `get_next_line.h` | Header |

---

**mhnatovs** — 42 School
