```
#include <stdio.h>
#include <stdint.h>

void fast_memcpy (uint8_t *to, uint8_t *from, size_t count)
{
    register size_t n = (count + 7) / 8;    
    uint8_t c = count % 8;
    switch (c)
    {
    case 0:       do { *to = *from++;
    case 7:        *to = *from++;
    case 6:        *to = *from++;
    case 5:        *to = *from++;
    case 4:        *to = *from++;
    case 3:        *to = *from++;
    case 2:        *to = *from++;
    case 1:        *to = *from++;
              } while (--n > 0);
    }
}
```
